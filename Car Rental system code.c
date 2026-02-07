#include <stdio.h>
#include <string.h>
#include <time.h>

void printAndSaveReceipt(int customerId, char customerName[], long long mobile,
                         int carId, char carName[], int costPerDay,
                         int rentedDays, int returnDays)
{
    FILE *fp;
    int baseAmount, extraDays = 0, extraCharge = 0, totalAmount;
    time_t t;
    time(&t);

    baseAmount = rentedDays * costPerDay;

    if (returnDays > rentedDays)
    {
        extraDays = returnDays - rentedDays;
        extraCharge = extraDays * 1000;
    }

    totalAmount = baseAmount + extraCharge;

    printf("\n\n================= CAR RENT RECEIPT =================");
    printf("\nDate & Time     : %s", ctime(&t));
    printf("Customer ID     : %d", customerId);
    printf("\nCustomer Name   : %s", customerName);
    printf("\nMobile Number   : %lld", mobile);
    printf("\nCar ID          : %d", carId);
    printf("\nCar Name        : %s", carName);
    printf("\nCost Per Day    : %d", costPerDay);
    printf("\nRented Days     : %d", rentedDays);
    printf("\nActual Days     : %d", returnDays);
    printf("\n----------------------------------------------------");
    printf("\nBase Amount     : %d", baseAmount);
    printf("\nExtra Charge    : %d", extraCharge);
    printf("\n----------------------------------------------------");
    printf("\nTOTAL AMOUNT    : %d", totalAmount);
    printf("\n====================================================\n");

    fp = fopen("receipt.txt", "a");

    fprintf(fp, "\n================= CAR RENT RECEIPT =================");
    fprintf(fp, "\nDate & Time     : %s", ctime(&t));
    fprintf(fp, "\nCustomer ID     : %d", customerId);
    fprintf(fp, "\nCustomer Name   : %s", customerName);
    fprintf(fp, "\nMobile Number   : %lld", mobile);
    fprintf(fp, "\nCar ID          : %d", carId);
    fprintf(fp, "\nCar Name        : %s", carName);
    fprintf(fp, "\nCost Per Day    : %d", costPerDay);
    fprintf(fp, "\nRented Days     : %d", rentedDays);
    fprintf(fp, "\nActual Days     : %d", returnDays);
    fprintf(fp, "\nBase Amount     : %d", baseAmount);
    fprintf(fp, "\nExtra Charge    : %d", extraCharge);
    fprintf(fp, "\nTOTAL AMOUNT    : %d", totalAmount);
    fprintf(fp, "\n====================================================\n");

    fclose(fp);
}

struct cars
{
    int id;
    char name[50];
    int costperday;
    int available;
};

int main()
{
    FILE *fp;
    int i, n, l;
    struct cars car[10] = {
        {0, "MARUTI", 5000, 1},
        {1, "MERCEDES", 9000, 1},
        {2, "FERRARI", 8000, 1},
        {3, "PORSCHE", 10000, 1},
        {4, "LAMBORGHINI", 7000, 1}};

    int id, rentedDays, returnDays, carCount = 5;
    int k = 0, m;
    long long num;
    char nam[50];

    do
    {
        printf("\n----------------------CAR RENTAL SYSTEM-----------------------");
        printf("\n1. ENTER NEW CUSTOMER DETAILS AND BOOK A CAR");
        printf("\n2. ADD NEW CAR");
        printf("\n3. DELETE A CAR CURRENTLY NOT AVAILABLE FOR RENT");
        printf("\n4. SHOW CAR BOOKINGS");
        printf("\n5. CALCULATE THE TOTAL COST OF A RENTED CAR AND PRINT THE BILL");
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("\nAvailable Car Option:-");
            printf("\n-------------------------------------------------------------");
            printf("\n| %-5s | %-15s | %-12s | %-10s |",
                   "Id", "Car Name", "Cost/Day", "Status");
            printf("\n-------------------------------------------------------------");

            for (i = 0; i < carCount; i++)
            {
                if (car[i].available == 1)
                {
                    printf("\n| %-5d | %-15s | %-12d | %-10s |",
                           car[i].id, car[i].name, car[i].costperday, "AVAILABLE");
                }
            }

            printf("\n-------------------------------------------------------------");

            fp = fopen("carbo.txt", "a");

            printf("\nEnter Customer Id: ");
            scanf("%d", &id);

            printf("Enter customer mobile no: ");
            scanf("%lld", &num);

            printf("Enter car number which you want to Rent: ");
            scanf("%d", &m);

            printf("Enter number of Days: ");
            scanf("%d", &rentedDays);

            printf("Enter customer name: ");
            getchar();
            gets(nam);
            if(car[m].available==0){
                printf("\nCar not available. Please choose another car.");
                fclose(fp);
                break;
            }

            car[m].available = 0;


            fprintf(fp, "customer id:%d customer mobile number:%lld car number:%d days:%d name:%s\n",
                    id, num, m, rentedDays, nam);

            fclose(fp);

            printf("\nBooking successful!");
            break;

        case 2:
            printf("\nEnter new car Id: ");
            scanf("%d", &car[carCount].id);

            if (car[carCount].id != car[carCount - 1].id + 1)
            {
                printf("\nCar ID should be consecutive.");
                break;
            }

            printf("Enter new car name: ");
            scanf("%s", car[carCount].name);

            printf("Enter cost per day: ");
            scanf("%d", &car[carCount].costperday);

            car[carCount].available = 1;
            carCount++;

            printf("\nNew car added successfully!");
            break;

        case 3:
            printf("\nEnter the car ID to be deleted: ");
            scanf("%d", &l);

            car[l].available = 0;
            printf("\nCar deleted successfully!");
            break;

        case 4:
            fp = fopen("carbo.txt", "r");
            if (fp == NULL)
            {
                printf("\nNo bookings found.");
                break;
            }

            char ch;
            while ((ch = fgetc(fp)) != EOF)
            {
                printf("%c", ch);
            }
            fclose(fp);
            break;

        case 5:
            printf("\nEnter customer id: ");
            scanf("%d", &id);

            printf("Enter customer name: ");
            getchar();
            gets(nam);

            printf("Enter customer mobile no: ");
            scanf("%lld", &num);

            printf("\nEnter the car number: ");
            scanf("%d", &l);

            printf("\nCar id:%d\nCar name:%s\nCost/day:%d\n",
                   car[l].id, car[l].name, car[l].costperday);

            printf("\nEnter rented days: ");
            scanf("%d", &rentedDays);

            printf("Enter actual return days: ");
            scanf("%d", &returnDays);

            printAndSaveReceipt(id, nam, num, car[l].id, car[l].name,
                                car[l].costperday, rentedDays, returnDays);
            break;

        default:
            printf("\nInvalid option selected");
        }

        printf("\nDo you want to continue? (1-YES / 0-NO): ");
        scanf("%d", &k);

    } while (k == 1);

    printf("\nTHANK YOU!!!");
    return 0;
}