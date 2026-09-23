#include <stdio.h>

int main() {
    int product, customer, orderNumber;
    float orderAmount, distance;
    float discountRate, discountAmount, finalAmount;
    float deliveryCharge, priorityCharge, totalAmount;
    int remainder;

    printf("E-Commerce Order Processing System\n\n");

    printf("Select Product Category:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    printf("Enter product category: ");
    scanf("%d", &product);

    printf("\nSelect Customer Category:\n");
    printf("1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    printf("Enter customer category: ");
    scanf("%d", &customer);

    printf("\nEnter Order Amount: Rs. ");
    scanf("%f", &orderAmount);

    printf("Enter Delivery Distance (km): ");
    scanf("%f", &distance);

    printf("Enter Order Number: ");
    scanf("%d", &orderNumber);

    switch (product) {
        case 1:
            switch (customer) {
                case 1:
                    discountRate = 5;
                    break;
                case 2:
                    discountRate = 10;
                    break;
                case 3:
                    discountRate = 15;
                    break;
                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        case 2:
            switch (customer) {
                case 1:
                    discountRate = 10;
                    break;
                case 2:
                    discountRate = 15;
                    break;
                case 3:
                    discountRate = 20;
                    break;
                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        case 3:
            switch (customer) {
                case 1:
                    discountRate = 8;
                    break;
                case 2:
                    discountRate = 12;
                    break;
                case 3:
                    discountRate = 18;
                    break;
                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        case 4:
            switch (customer) {
                case 1:
                    discountRate = 7;
                    break;
                case 2:
                    discountRate = 14;
                    break;
                case 3:
                    discountRate = 20;
                    break;
                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        default:
            printf("Invalid product category.\n");
            return 0;
    }

    discountAmount = orderAmount * discountRate / 100;
    finalAmount = orderAmount - discountAmount;

    if (finalAmount >= 5000 || customer == 2 || customer == 3) {
        deliveryCharge = 0;
    } else {
        deliveryCharge = distance * 50;
    }

    if ((customer == 2 || customer == 3) && orderAmount >= 10000) {
        priorityCharge = 500;
    } else {
        priorityCharge = 0;
    }

    totalAmount = finalAmount + deliveryCharge + priorityCharge;

    remainder = orderNumber % 4;

    printf("\n----- Final Order Report -----\n");

    printf("Product Category: ");
    switch (product) {
        case 1:
            printf("Electronics\n");
            break;
        case 2:
            printf("Clothing\n");
            break;
        case 3:
            printf("Books\n");
            break;
        case 4:
            printf("Household\n");
            break;
    }

    printf("Customer Category: ");
    switch (customer) {
        case 1:
            printf("Regular\n");
            break;
        case 2:
            printf("Premium\n");
            break;
        case 3:
            printf("Corporate\n");
            break;
    }

    printf("Original Order Amount: Rs. %.2f\n", orderAmount);
    printf("Discount Percentage: %.0f%%\n", discountRate);
    printf("Discount Amount: Rs. %.2f\n", discountAmount);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);
    printf("Delivery Distance: %.2f km\n", distance);

    printf("Shipping Status: %s\n",
           (deliveryCharge == 0) ? "Free Shipping" : "Paid Shipping");

    printf("Delivery Charges: Rs. %.2f\n", deliveryCharge);

    printf("Priority Delivery: %s\n",
           (priorityCharge == 500) ? "Yes" : "No");

    printf("Priority Charges: Rs. %.2f\n", priorityCharge);

    printf("Processing Group: ");

    switch (remainder) {
        case 0:
            printf("Processing Group A\n");
            break;
        case 1:
            printf("Processing Group B\n");
            break;
        case 2:
            printf("Processing Group C\n");
            break;
        case 3:
            printf("Processing Group D\n");
            break;
    }

    printf("Total Amount Payable: Rs. %.2f\n", totalAmount);

    return 0;
}
