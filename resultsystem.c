#include <stdio.h>

int main() {
    int department;
    int theory, practical, attendance;
    int theoryReq, practicalReq, attendanceReq;
    int remainder;
    
    printf("University Examination Result Processing System\n\n");

    printf("Select Department:\n");
    printf("1. Computer Science\n");
    printf("2. Electrical Engineering\n");
    printf("3. Business Administration\n");
    printf("4. Mathematics\n");
    printf("Enter department choice: ");
    scanf("%d", &department);

    printf("Enter theory marks: ");
    scanf("%d", &theory);

    printf("Enter practical marks: ");
    scanf("%d", &practical);

    printf("Enter attendance percentage: ");
    scanf("%d", &attendance);

    switch (department) {
        case 1:
            theoryReq = 50;
            practicalReq = 40;
            attendanceReq = 75;
            break;

        case 2:
            theoryReq = 55;
            practicalReq = 45;
            attendanceReq = 75;
            break;

        case 3:
            theoryReq = 50;
            practicalReq = 35;
            attendanceReq = 80;
            break;

        case 4:
            theoryReq = 60;
            practicalReq = 40;
            attendanceReq = 75;
            break;

        default:
            printf("Invalid department choice.\n");
            return 0;
    }

    remainder = theory % 3;

    printf("\n----- Final Report -----\n");

    printf("Department: ");
    switch (department) {
        case 1:
            printf("Computer Science\n");
            break;
        case 2:
            printf("Electrical Engineering\n");
            break;
        case 3:
            printf("Business Administration\n");
            break;
        case 4:
            printf("Mathematics\n");
            break;
    }

    printf("Theory Marks: %d\n", theory);
    printf("Practical Marks: %d\n", practical);
    printf("Attendance: %d%%\n", attendance);

    printf("Theory Requirement: %d\n", theoryReq);
    printf("Practical Requirement: %d\n", practicalReq);
    printf("Attendance Requirement: %d%%\n", attendanceReq);

    printf("Distinction: %s\n",
           (theory >= 85 && practical >= 80 && attendance >= 90)
           ? "Eligible"
           : "Not Eligible");

    printf("Seat Category: ");

    switch (remainder) {
        case 0:
            printf("A\n");
            break;
        case 1:
            printf("B\n");
            break;
        case 2:
            printf("C\n");
            break;
    }

    printf("Final Result: %s\n",
           (theory >= theoryReq && practical >= practicalReq && attendance >= attendanceReq)
           ? "Passed"
           : "Failed");

    return 0;
}
