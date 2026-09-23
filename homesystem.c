#include <stdio.h>

int main()
{
    int status = 0;
    int operation, device, mode;

    int door = 1 << 0;
    int alarm = 1 << 1;
    int cctv = 1 << 2;
    int motion = 1 << 3;

    printf("Smart Home Security Controller\n\n");

    printf("Select Operation:\n");
    printf("1. Activate Device\n");
    printf("2. Deactivate Device\n");
    printf("3. Check Device Status\n");
    printf("4. Toggle Device\n");
    printf("5. Security Mode\n");
    printf("Enter operation: ");
    scanf("%d", &operation);

    switch (operation)
    {
        case 1:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch (device)
            {
                case 1:
                    status = status | door;
                    printf("Main Door Lock activated.\n");
                    break;

                case 2:
                    status = status | alarm;
                    printf("Alarm System activated.\n");
                    break;

                case 3:
                    status = status | cctv;
                    printf("CCTV Camera activated.\n");
                    break;

                case 4:
                    status = status | motion;
                    printf("Motion Sensor activated.\n");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 2:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch (device)
            {
                case 1:
                    status = status & ~door;
                    printf("Main Door Lock deactivated.\n");
                    break;

                case 2:
                    status = status & ~alarm;
                    printf("Alarm System deactivated.\n");
                    break;

                case 3:
                    status = status & ~cctv;
                    printf("CCTV Camera deactivated.\n");
                    break;

                case 4:
                    status = status & ~motion;
                    printf("Motion Sensor deactivated.\n");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 3:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch (device)
            {
                case 1:
                    printf("Main Door Lock: %s\n",
                           (status & door) ? "Active" : "Inactive");
                    break;

                case 2:
                    printf("Alarm System: %s\n",
                           (status & alarm) ? "Active" : "Inactive");
                    break;

                case 3:
                    printf("CCTV Camera: %s\n",
                           (status & cctv) ? "Active" : "Inactive");
                    break;

                case 4:
                    printf("Motion Sensor: %s\n",
                           (status & motion) ? "Active" : "Inactive");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 4:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch (device)
            {
                case 1:
                    status = status ^ door;
                    printf("Main Door Lock toggled.\n");
                    break;

                case 2:
                    status = status ^ alarm;
                    printf("Alarm System toggled.\n");
                    break;

                case 3:
                    status = status ^ cctv;
                    printf("CCTV Camera toggled.\n");
                    break;

                case 4:
                    status = status ^ motion;
                    printf("Motion Sensor toggled.\n");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 5:
            printf("\nSelect Security Mode:\n");
            printf("1. Home Mode\n");
            printf("2. Away Mode\n");
            printf("3. Night Mode\n");
            printf("Enter mode: ");
            scanf("%d", &mode);

            switch (mode)
            {
                case 1:
                    status = status | door | cctv;
                    printf("Home Mode activated.\n");
                    break;

                case 2:
                    status = status | door | alarm | cctv | motion;
                    printf("Away Mode activated.\n");
                    break;

                case 3:
                    status = status | door | alarm | motion;
                    printf("Night Mode activated.\n");
                    break;

                default:
                    printf("Invalid security mode.\n");
            }
            break;

        default:
            printf("Invalid operation.\n");
    }

    printf("\nSecurity Status\n");
    printf("-------------------------\n");

    printf("Door     [1]: %s\n",
           (status & door) ? "Active" : "Inactive");

    printf("Alarm    [2]: %s\n",
           (status & alarm) ? "Active" : "Inactive");

    printf("CCTV     [4]: %s\n",
           (status & cctv) ? "Active" : "Inactive");

    printf("Motion   [8]: %s\n",
           (status & motion) ? "Active" : "Inactive");

    printf("\nBinary-equivalent status: ");

    printf("%d", (status & 8) ? 1 : 0);
    printf("%d", (status & 4) ? 1 : 0);
    printf("%d", (status & 2) ? 1 : 0);
    printf("%d\n", (status & 1) ? 1 : 0);

    if ((status & door) && (status & alarm) &&
        (status & cctv) && (status & motion))
    {
        printf("Complete Security System: FULLY ARMED\n");
    }
    else
    {
        printf("Complete Security System: NOT FULLY ARMED\n");
    }

    printf("System value: %d\n", status);

    return 0;
}
