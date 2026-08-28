#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Booking_Management.h"
#include "Customer_Management.h"

int Book_Tour()
{
    FILE *file1;

    file1 = fopen("Data/Booking Management.txt","a");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {
        struct booking booking;

        printf("\n=================================== BOOKING TOUR ==============================\n\n");
        printf("\n\nEnter Booking info :\n\n");

        printf("1.Booking ID no = ");
        scanf(" %[^\n]",booking.bookingID);

        while(check_booking_id(booking.bookingID) == 1)
        {
            printf("This Booking ID is not available..Try another one.....\n\n");

            printf("1.Enter Booking ID no = ");
            scanf(" %[^\n]",booking.bookingID);

        }

        printf("2.Customer ID no = ");
        scanf(" %[^\n]",booking.customerID);

        if(check_customer_id(booking.customerID) == 0)
        {
            printf("\n-------This Customer ID does not exist.--------\n");
            return 0;
        }

        printf("3.Tour ID no = ");
        scanf(" %[^\n]",booking.tourID);

        if(check_tour_id(booking.tourID) == 0)
        {
            printf("\n-------This Tour ID does not exist.-------\n");
            return 0;
        }

        printf("4.Customer Name : ");
        scanf(" %[^\n]",booking.customerName);

        printf("5.Booking Date : ");
        scanf(" %[^\n]",booking.bookingDate);

        printf("6.Number of People : ");
        scanf("%d",&booking.numberOfPeople);

        while(Select_Tour_Type(booking.tourType) == 0)
        {
            printf("Please select a valid option.\n");
        }
        while(Select_Traveler_Type(booking.TravelarType) == 0)
        {
            printf("Please select a valid option.\n");
        }

        fprintf(file1,
                "\n\n1.Booking ID: %s\n"
                "2.Customer ID: %s\n"
                "3.Tour ID: %s\n"
                "4.Customer Name: %s\n"
                "5.Booking Date: %s\n"
                "6.Number of People: %d\n"
                "7.Traveler Type: %s\n"
                "8.Tour Type: %s\n"
                "9.Total Cost: Pending\n"
                "10.Amount paid: 0.00\n"
                "11.Payment Status: Pending\n"
                "12.Booking Status: Pending\n",
                booking.bookingID,
                booking.customerID,
                booking.tourID,
                booking.customerName,
                booking.bookingDate,
                booking.numberOfPeople,
                booking.TravelarType,
                booking.tourType);

        fclose(file1);


    }
    printf("\n\n======================BOOKING HAS BEEN ADDED SUCCESSFULY======================\n");



    return 0;
}

int View_All_Bookings()
{
    FILE *file1;
    char line[200];
    int count_line3=1;
    int i=1;
    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {
        printf("===================================================ALL BOOOKING INFO===============================================\n\n");
        while (fgets(line, sizeof(line), file1) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            if(i==1)
            {
                printf("\nBooking No %d :\n",count_line3);
            }

            else if((i%13)==1)
            {
                count_line3++;
                printf("\nBooking No %d :\n",count_line3);
            }

            printf("%s\n", line);
            i++;
        }

        fclose(file1);
        printf("\n\n================================================================================================================\n\n");


    }

    return 0;
}
int Search_Booking()
{
    int count_line1=0;
    int count_line2=0;
    char line[200];
    char search[20];
    int found=0;

    char find[30]="1.Booking ID: ";

    printf("Enter the Booking ID you want to Find = ");
    scanf("%s",search);
    strcat(find,search);
    FILE *file1;
    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {

                found++;
                break;

            }

        }
        fclose(file1);

    }

    if(found==1)
    {

        file1 = fopen("Data/Booking Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            system("cls");
            printf("\n\n==========================================SEARCHED BOOKING INFO=============================\n\n");

            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=count_line1 && count_line2<=(count_line1 + 12))
                {
                    printf("%s\n", line);

                }
                if(count_line2 == count_line1 + 12)
                {
                    break;
                }

            }

            fclose(file1);
            printf("\n\n=============================================================================================\n\n");

        }

    }

    else
    {
        printf("\nGiven Booking ID is Invalid or Not exist\n");
    }

    return 0;
}

int Update_Booking()
{
    printf("======================== UPDATE BOOKING =======================\n\n");
    int count_line1=0;
    int count_line2=0;
    int count_line3=0;
    int pend=0;
    int cancel=0;
    int confirm=0;
    int found =0;
    char line[200];
    char search[20];
    char find[30]="1.Booking ID: ";
    printf("Enter the Booking ID you want to search = ");
    scanf("%s",search);
    strcat(find,search);
    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Booking Management.txt","r");
    file2 = fopen("Data/Booking Management_temp.txt","w");
    if(file1==NULL || file2==NULL)
    {
        printf("File does not exist");
    }
    else
    {


        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {

                found=1;
                 break;

            }


        }

        rewind(file1);
        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line3++;
            line[strcspn(line, "\n")] = '\0';

             if(count_line3>=count_line1 && count_line3<=(count_line1 + 12))

                {
                         if(strcmp(line,"12.Booking Status: Pending") == 0)
                    {
                          pend=1;
                    }

                      if(strcmp(line,"12.Booking Status: canceled(Before Tour)") == 0 || strcmp(line,"12.Booking Status: canceled") == 0 )
                    {
                          cancel=1;
                    }

                         if(strcmp(line,"12.Booking Status: confirmed") == 0)
                    {
                          confirm=1;
                    }


                }


        }



        if(found == 1 && pend==1)
        {

            rewind(file1);
            while (fgets(line, sizeof(line), file1) != NULL)
            {

                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2==count_line1)
                {


                    struct booking booking;
                    printf("\n\nEnter Booking info :\n\n");



                    printf("1.Customer ID no = ");
                    scanf(" %[^\n]",booking.customerID);

                    if(check_customer_id(booking.customerID) == 0)
                    {
                        printf("\n-------This Customer ID does not exist.--------\n");
                        return 0;
                    }

                    printf("2.Tour ID no = ");
                    scanf(" %[^\n]",booking.tourID);

                    if(check_tour_id(booking.tourID) == 0)
                    {
                        printf("\n-------This Tour ID does not exist.-------\n");
                        return 0;
                    }

                    printf("3.Customer Name : ");
                    scanf(" %[^\n]",booking.customerName);

                    printf("4.Booking Date : ");
                    scanf(" %[^\n]",booking.bookingDate);

                    printf("5.Number of People : ");
                    scanf("%d",&booking.numberOfPeople);

                    while(Select_Tour_Type(booking.tourType) == 0)
                    {
                        printf("Please select a valid option.\n");
                    }
                    while(Select_Traveler_Type(booking.TravelarType) == 0)
                    {
                        printf("Please select a valid option.\n");
                    }

                    fprintf(file2,
                            "1.Booking ID: %s\n"
                            "2.Customer ID: %s\n"
                            "3.Tour ID: %s\n"
                            "4.Customer Name: %s\n"
                            "5.Booking Date: %s\n"
                            "6.Number of People: %d\n"
                            "7.Traveler Type: %s\n"
                            "8.Tour Type: %s\n"
                            "9.Total Cost: Pending\n"
                            "10.Amount paid: 0.00\n"
                            "11.Payment Status: Pending\n"
                            "12.Booking Status: Pending\n\n",
                            search,
                            booking.customerID,
                            booking.tourID,
                            booking.customerName,
                            booking.bookingDate,
                            booking.numberOfPeople,
                            booking.TravelarType,
                            booking.tourType);


                    printf("\n-------------Your Booking ID info has been Updated.-------------\n");
                }

                else
                {

                    if(count_line2>=count_line1 && count_line2<=(count_line1 + 12))
                    {
                        continue;
                    }

                    fprintf(file2,"%s\n", line);


                }
            }

            fclose(file1);
            fclose(file2);

            if(remove("Data/Booking Management.txt") != 0)
            {
                printf("\nFailed to delete Old file.\n");
            }


            if(rename("Data/Booking Management_temp.txt", "Data/Booking Management.txt") != 0)
            {
                printf("Failed to rename the file.\n");
            }

        }

       else if(found==1 && cancel==1)
        {
            system("cls");
            printf("=========================================WARNING==============================================\n\n");
            printf("===========================CANCELED BOOKING CAN'T BE UPDATED==================================\n\n");
            printf("==============================================================================================\n\n\n");
        }

      else if(found==1 && confirm==1)
        {
            system("cls");
            printf("=========================================WARNING===========================================\n\n");

            printf("============================CONFIRM BOOKING CAN'T BE UPDATED===============================\n\n");
            printf("===========================================================================================\n\n\n");

        }

        else
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Booking Management_temp.txt");
            printf("Booking ID not found.");
        }

    }
    return 0;
}


int cancel_booking_check()
{
    system("cls");

    char search[30];
    int prefer=0;
    printf("\nEnter the Booking ID which you want to cancel :");
    scanf("%s",search);

    printf("\nAre you sure you want to Cancel Booking ID No - %s ?\n",search);
    printf("1.Yes.\n");
    printf("2.No.\n");
    printf("Enter your choice : ");
    scanf("%d",&prefer);
    switch(prefer)
    {
    case 1:
        Cancel_Booking(search);
        break;
    case 2:
        printf("Booking cancellation has been stopped.\n");
        break;

    default:

        printf("Invalid choice.Try again.......\n");
        break;

    }
    return 0;
}


int Cancel_Booking(char search[])
{


    int count_line1=0;
    int count_line2=0;
    int count_line3=0;
    int found =0;
    int confirm=0,cancel=0,pending=0;
    char line[200];
    char find[30]="1.Booking ID: ";

    strcat(find,search);
    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Booking Management.txt","r");
    file2 = fopen("Data/Booking Management_temp.txt","w");
    if(file1==NULL || file2==NULL)
    {
        printf("File does not exist");
    }
    else
    {


        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                found++;
                break;
            }

        }


        rewind(file1);

        while (fgets(line, sizeof(line), file1) != NULL)
        {

            count_line3++;
            line[strcspn(line, "\n")] = '\0';

            if(count_line3==(count_line1+11))
            {

                if(strcmp(line,"12.Booking Status: confirmed")==0)
                {
                    confirm=1;
                }
                else if(strcmp(line,"12.Booking Status: canceled")==0)
                {
                    cancel=1;
                }
                else if(strcmp(line,"12.Booking Status: Pending")==0)
                {
                    pending=1;
                }
                break;
            }
        }

        if(found == 1 && cancel==0)
        {



            rewind(file1);
            while (fgets(line, sizeof(line), file1) != NULL)
            {

                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2==(count_line1+10))
                {
                    if(confirm==1)
                    {
                        fprintf(file2,
                                "11.Payment Status: Half of the amount will be refunded soon.\n"
                                "12.Booking Status: canceled\n");

                    }
                    else if(pending==1)
                    {
                        fprintf(file2,
                                "11.Payment Status: No refund will be given as the booking was unpaid.\n"
                                "12.Booking Status: canceled(Before Tour)\n");
                    }

                }

                else
                {

                    if(count_line2>=(count_line1+10) && count_line2<=(count_line1 + 11))
                    {
                        continue;
                    }

                    fprintf(file2,"%s\n", line);


                }

            }

            fclose(file1);
            fclose(file2);

            if(remove("Data/Booking Management.txt") != 0)
            {
                printf("Failed to delete the old file.\n");
            }

            if(rename("Data/Booking Management_temp.txt", "Data/Booking Management.txt") != 0)
            {
                printf("Failed to rename the file.\n");
            }

            int count_line5=0;
            FILE *file3;
            file3 = fopen("Data/Booking Management.txt","r");
            if(file3==NULL)
            {
                printf("File does not exist");
            }
            else
            {
                system("cls");
                printf("\n===========================BOOKING CANCELLED SUCCUSSFULL ======================\n\n");

                while (fgets(line, sizeof(line), file3) != NULL)
                {
                    count_line5++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line5>=count_line1 && count_line5<=(count_line1 + 12))
                    {
                        printf("%s\n", line);

                    }
                    if(count_line5 == count_line1 + 12)
                    {
                        break;
                    }

                }

                fclose(file3);
                printf("\n\n===============================================================================\n\n");

            }


        }
        else if(found==0)
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Booking Management_temp.txt");
            printf("Booking ID not found.");
        }
        else if(cancel==1)
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Booking Management_temp.txt");
            printf("This Booking Already had been canceled before.");
        }

    }
    return 0;
}

int Cust_Book_hist()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int i=0;
    int n;
    char line[200];
    char search[20];
    int found=0;
    char find[50]="2.Customer ID: ";
    printf("Enter the Customer ID : ");
    scanf("%s",search);


    strcat(find,search);
    FILE *file1;
    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {

                found++;

                count_line3[i]=count_line1;
                i++;
                n=i;

            }


        }
        fclose(file1);

    }


    if(found>=1)
    {


        file1 = fopen("Data/Booking Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            system("cls");
            printf("====================================CUSTOMER ALL BOOKING HISTORY===========================\n\n");

            for(i=0; i<n; i++)
            {

                while (fgets(line, sizeof(line), file1) != NULL)
                {
                    count_line2++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line2>=(count_line3[i] - 1) && count_line2<=(count_line3[i] + 11))
                    {
                        printf("%s\n", line);

                    }
                    if(count_line2 == count_line3[i] + 11)
                    {
                        break;
                    }

                }

            }
            printf("\n\n===========================================================================================\n\n");


            fclose(file1);

        }

    }

    else
    {
        printf("\n======THIS CUSTOMER HAS MADE NO BOOKING YET=======\n\n");
    }

    return 0;

}

int Tour_Book_hist()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int i=0;
    int n;
    char line[200];
    char search[20];
    int found=0;
    char find[50]="3.Tour ID: ";
    printf("Enter the Tour ID : ");
    scanf("%s",search);


    strcat(find,search);
    FILE *file1;
    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {

                found++;

                count_line3[i]=count_line1;
                i++;
                n=i;

            }


        }
        fclose(file1);

    }


    if(found>=1)
    {

        file1 = fopen("Data/Booking Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            system("cls");
            printf("=======================ALL BOOKING HISTORY OF THIS TOUR ID=======================\n\n");
            for(i=0; i<n; i++)
            {
                printf("No %d Booking\n\n",i+1);

                while (fgets(line, sizeof(line), file1) != NULL)
                {
                    count_line2++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line2>=(count_line3[i] - 2) && count_line2<=(count_line3[i] + 10))
                    {
                        printf("%s\n", line);

                    }
                    if(count_line2 == (count_line3[i] + 10))
                    {
                        break;
                    }

                }

            }
            printf("\n\n====================================================================================\n\n");

            fclose(file1);

        }

    }

    else
    {
        printf("\n=========THIS TOUR ID HAVE NO BOOKING YET==============\n\n");
    }

}

int View_Booking_History()
{

    int choice;
    printf("\n======================================== BOOKING HISTORY ==============================\n\n");
    printf("Which history you want to see?\n");
    printf("1.Customer Booking History.\n");
    printf("2.Tour ID Booking History\n\n");
    printf("Enter your Choice: ");
    scanf("%d",&choice);
    system("cls");

    switch(choice)
    {
    case 1:
        Cust_Book_hist();
        break;
    case 2:
        Tour_Book_hist();

    }
    return 0;
}

int check_booking_id(char bookingID[])
{

    char line[200];
    int found=0;
    char find[30]="1.Booking ID: ";
    strcat(find, bookingID);
    FILE *file1;
    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {

            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                found=1;
                break;

            }

        }
        fclose(file1);

    }
    return found;
}


int check_customer_id(char customerID[])
{


    char line[200];
    char find[30]="2.Unique ID: ";
    int found=0;
    strcat(find, customerID);
    FILE *file1;
    file1 = fopen("Data/Customer Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {

            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                found=1;
                break;

            }

        }
        fclose(file1);

    }
    return found;

}

int check_tour_id(char tourID[])
{
    char line[200];
    int got=0;
    char find[30]="1.Tour ID: ";
    strcat(find, tourID);
    FILE *file1;
    file1 = fopen("Data/Tour package Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                got=1;
                break;

            }

        }
        fclose(file1);
        return got;

    }
    return 0;
}



int Select_Tour_Type(char tourType[])
{
    int choice;

    printf("\n========== TOUR TYPE ==========\n");
    printf("1. Normal\n");
    printf("2. Premium\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        strcpy(tourType, "normal");
        break;

    case 2:
        strcpy(tourType, "premium");
        break;

    default:
        printf("Invalid choice. Please try again.\n");
        return 0;
    }

    return 1;
}

int Select_Traveler_Type(char travelerType[])
{
    int choice;

    printf("\n========== TRAVELER TYPE ==========\n");
    printf("1. Person\n");
    printf("2. Couple\n");
    printf("3. Foreigner\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        strcpy(travelerType, "person");
        break;

    case 2:
        strcpy(travelerType, "couple");
        break;

    case 3:
        strcpy(travelerType, "foreigner");
        break;

    default:
        printf("Invalid choice. Please try again.\n");
        return 0;
    }

    return 1;
}
