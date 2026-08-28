#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Payment_Management.h"

int Calculate_Total_Cost()
{
    printf("===============TOTAL COST CALCULATION==================\n\n");
    int count_line1=0;
    int count_line2=0;
    char line[200];
    char search[20];
    int found=0;
    int count_line3;

    char tourID[50];
    int numberOfPeople;
    char travelarType[50];
    char tourType[50];
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
                count_line3=count_line1;
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
            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=count_line1 && count_line2<=(count_line1 + 12))
                {

                    if (strncmp(line, "3.Tour ID:", strlen("3.Tour ID:")) == 0)
                    {
                        sscanf(line, "3.Tour ID: %[^\n]", tourID);
                    }

                    else if (strncmp(line, "6.Number of People:", strlen("6.Number of People:")) == 0)
                    {
                        sscanf(line, "6.Number of People: %d ", &numberOfPeople);
                    }

                    else if (strncmp(line, "7.Traveler Type:", strlen("7.Traveler Type:")) == 0)
                    {
                        sscanf(line, "7.Traveler Type: %[^\n]", travelarType);
                    }

                    else if (strncmp(line, "8.Tour Type:", strlen("8.Tour Type:")) == 0)
                    {
                        sscanf(line, "8.Tour Type: %[^\n]", tourType);
                    }

                }
                if(count_line2 == count_line1 + 12)
                {
                    break;
                }

            }

            fclose(file1);

        }


    }
    else
    {
        printf("\n======GIVEN BOOKING ID IS INVALID OR NOT EXIST=========\n");
    }


    count_line1=0;
    count_line2=0;
    float normal1, premium1;
    found=0;
    strcpy(find, "1.Tour ID: ");
    strcat(find,tourID);
    file1 = fopen("Data/Tour package Management.txt","r");
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

        file1 = fopen("Data/Tour package Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=(count_line1+17) && count_line2<=(count_line1 + 19))
                {
                    printf("%s\n", line);

                    if (strncmp(line,"Cost Per Person", strlen("Cost Per Person")) == 0 && strcmp(travelarType, "person") == 0)
                    {
                        //sscanf(line, "3.Tour ID: %[^\n]", tourID);
                        sscanf(line, "Cost Per Person (Normal and Premium package): %f and %f",&normal1,&premium1);

                    }

                    else  if (strncmp(line, "Cost Per Couple", strlen("Cost Per Couple")) == 0 && strcmp(travelarType, "couple") == 0)
                    {
                        sscanf(line, "Cost Per Couple (Normal and Premium package): %f and %f", &normal1,&premium1);

                    }

                    else  if (strncmp(line, "Cost Per Foreigner", strlen("Cost Per Foreigner")) == 0 && strcmp(travelarType, "foreigner") == 0)
                    {

                        sscanf(line, "Cost Per Foreigner (Normal and Premium package): %f and %f", &normal1,&premium1);

                    }


                }
                if(count_line2 == count_line1 + 19)
                {
                    break;
                }

            }

            fclose(file1);

        }

    }

    else
    {
        printf("\n======GIVEN TOUR ID IS INVALID OR NOT EXIST=========\n");

    }

    float price;

    if(strcmp(tourType,"normal")==0)
    {
        price = normal1*numberOfPeople;
    }
    else if(strcmp(tourType,"premium")==0)
    {
        price = premium1*numberOfPeople;
    }

    printf("\n---------Total cost of your booking is %.2f---------\n ", price);





    FILE *file2;
    count_line2 = 0;
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

            count_line2++;
            line[strcspn(line, "\n")] = '\0';

            if(count_line2==(count_line3+8))
            {

                fprintf(file2,
                        "9.Total Cost: %.2f \n",
                        price);

            }

            else
            {
                fprintf(file2,"%s\n", line);
            }

        }
        printf("\n----------------Total cost has been added successfully.--------------\n\n");


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

    }
    return 0;
}

int payment_by_bookID()
{
    char search[20];

    printf("Enter the Booking ID which you want to Make Payment: ");
    scanf("%s", search);
    Make_Payment(search);
    return 0;
}


int Make_Payment(char search[])
{

    printf("======================== MAKING PAYMENT ==============================\n\n");
    int count_line1=0;
    int count_line2=0;
    int count_line3=0;
    int count_line4=0;
    int count_line5=0;

    char line[200];

    int found=0;

    int book1=0;
    int book2=0;
    int book3=0;

    float price = 0.0f;
    float payment;
    char tourID[50];
    int numberOfPeople;
    char travelarType[50];
    char tourType[50];
    char date[30];
    char find[30]="1.Booking ID: ";

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
                count_line3=count_line1;
                count_line4=count_line1;
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

            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=count_line1 && count_line2<=(count_line1 + 12))
                {

                    if (strncmp(line, "3.Tour ID:", strlen("3.Tour ID:")) == 0)
                    {
                        sscanf(line, "3.Tour ID: %[^\n]", tourID);
                    }

                    else if (strncmp(line, "6.Number of People:", strlen("6.Number of People:")) == 0)
                    {
                        sscanf(line, "6.Number of People: %d ", &numberOfPeople);
                    }

                    else if (strncmp(line, "7.Traveler Type:", strlen("7.Traveler Type:")) == 0)
                    {
                        sscanf(line, "7.Traveler Type: %[^\n]", travelarType);
                    }

                    else if (strncmp(line, "8.Tour Type:", strlen("8.Tour Type:")) == 0)
                    {
                        sscanf(line, "8.Tour Type: %[^\n]", tourType);
                    }

                }
                if(count_line2 == count_line1 + 12)
                {
                    break;
                }

            }

            fclose(file1);

        }

    }

    else
    {
        printf("\nGiven Booking ID is Invalid or Not exist");
    }


    count_line1=0;
    count_line2=0;
    float normal1 = 0.0f;
    float premium1 = 0.0f;
    int got=0;
    strcpy(find, "1.Tour ID: ");
    strcat(find,tourID);
    file1 = fopen("Data/Tour package Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {
            count_line5++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                got++;
                break;

            }

        }
        fclose(file1);

    }

    if(got==1)
    {

        file1 = fopen("Data/Tour package Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {

            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=(count_line5+17) && count_line2<=(count_line5 + 19))
                {


                    if (strncmp(line,"Cost Per Person", strlen("Cost Per Person")) == 0 && strcmp(travelarType, "person") == 0)
                    {

                        sscanf(line, "Cost Per Person (Normal and Premium package): %f and %f",&normal1,&premium1);

                    }

                    else  if (strncmp(line, "Cost Per Couple", strlen("Cost Per Couple")) == 0 && strcmp(travelarType, "couple") == 0)
                    {
                        sscanf(line, "Cost Per Couple (Normal and Premium package): %f and %f", &normal1,&premium1);

                    }

                    else  if (strncmp(line, "Cost Per Foreigner", strlen("Cost Per Foreigner")) == 0 && strcmp(travelarType, "foreigner") == 0)
                    {

                        sscanf(line, "Cost Per Foreigner (Normal and Premium package): %f and %f", &normal1,&premium1);

                    }


                }

                if(count_line2 == count_line5 + 19)
                {
                    break;
                }

            }


            fclose(file1);

        }


        file1 = fopen("Data/Booking Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            count_line2=0;
            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2==(count_line4+11))
                {
                    if (strcmp(line, "12.Booking Status: canceled") == 0  || strcmp(line, "12.Booking Status: canceled(Before Tour)") == 0)
                    {
                        book3++;

                    }

                    else if (strcmp(line, "12.Booking Status: Pending") == 0 )
                    {
                        book1++;
                    }

                    else if (strcmp(line, "12.Booking Status: confirmed") == 0 )
                    {
                        book2++;
                    }


                }

            }


            fclose(file1);

        }


        if(book1==1)
        {

            if(normal1 == 0.0f && premium1 == 0.0f)
            {
                printf("The price is not found\n");

            }


            else if(normal1 != 0.0f && premium1 != 0.0f)
            {

                if(strcmp(tourType,"normal")==0)
                {
                    price = normal1*numberOfPeople;
                }
                else if(strcmp(tourType,"premium")==0)
                {
                    price = premium1*numberOfPeople;
                }


                printf("\n==================================================\n\n");
                printf("Total Cost of your booking is : %f\n",price);
                printf("Enter today date: ");
                scanf(" %[^\n]",date);
                printf("\nYou must pay the full Amount\n\n");
                printf("Enter the Paid amount = ");
                scanf("%f",&payment);

                printf("\n==================================================\n\n");

                if((int)price==(int)payment)
                {

                    system("cls");
                    printf("\n===========================PAYMENT SUCCESSFUL===================\n\n");
                    printf("Booking ID: %s\n",search);
                    printf("Amount Paid : %f\n",payment);
                    printf("Payment Status: Paid\n");
                    printf("Booking Status: Confirmed\n");

                    printf("\n================================================================\n\n");


                    FILE *file2;
                    count_line2 = 0;
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

                            count_line2++;
                            line[strcspn(line, "\n")] = '\0';

                            if(count_line2==(count_line3+8))
                            {

                                fprintf(file2,
                                        "9.Total Cost: %.2f \n"
                                        "10.Amount paid:%.2f \n"
                                        "11.Payment Status: paid( %s )\n"
                                        "12.Booking Status: confirmed\n",
                                        price,
                                        payment,
                                        date);

                            }

                            else
                            {
                                if(count_line2>=(count_line3 + 8) && count_line2<=(count_line3 + 11))
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

                    }

                }

                else  if ((int)payment < (int)price)
                {
                    printf("-----------INSUFFICIENT PAYMENT.TRY AGAIN------------\n");
                }

                else
                {
                    printf("==============EXTRA PAYMENT RECEIVED=================\n");
                }


            }

        }

        else if(book2==1)
        {
            printf("\n\n===============THIS BOOKING IS ALREADY CONFIRMED AND DONE PAYMENET==============\n");
        }

        else if(book3==1)
        {
            printf("\n=============================THIS BOOKING IS CANCELED==============================\n");
        }


    }

    else
    {
        printf("\nBooking Tour ID is Invalid or Not exist");
    }

    return 0;

}

int View_Payment_History()
{
    int choice;

    printf("\n--------- ----------PAYMENT HISTORY --------------------\n");
    printf("1.View Payment History by Booking ID\n");
    printf("2.View All Payment History by Tour ID\n");
    printf("3.View All Payment Records\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    system("cls");

    switch(choice)
    {
    case 1:
        View_Payment_By_Booking_ID();
        break;

    case 2:
        View_ALL_Payment_By_Tour_ID();
        break;
    case 3:
        View_All_Payment_Records();
        break;

    default:
        printf("Invalid choice! Please try again.\n");
    }
    return 0;
}

int View_Payment_By_Booking_ID()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3=0;
    char line[200];
    char search[20];
    int found=0;
    int confirm=0;
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


    file1 = fopen("Data/Booking Management.txt","r");

    if(file1==NULL)
    {
        printf("File does not exist");
    }

    else
    {

        while(fgets(line,sizeof(line),file1)!=NULL)
        {
            count_line3++;
            line[strcspn(line,"\n")] = '\0';

            if(count_line3 == count_line1 + 11)
            {
                if(strcmp(line,"12.Booking Status: confirmed") == 0)
                {
                    confirm++;
                }
                break;
            }
        }
        fclose(file1);
    }

    if(found==1 && confirm==1)
    {

        file1 = fopen("Data/Booking Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            system("cls");
            printf("=============BOOKING INFO===============\n\n");

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
            printf("\n=========================================\n\n");

            fclose(file1);

        }

    }

    else if(found==0)
    {
        printf("\nGiven Booking ID is Invalid or Not exist\n");
    }
    else if(confirm==0)
    {
        printf("This booking id is not made payment yet.\n");
    }
    return 0;

}

int View_All_Payment_Records()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int i=0;
    int n;
    char line[200];
    int found=0;

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
            if(strcmp(line,"12.Booking Status: confirmed") == 0)
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
            printf("============ALL CONFIRMED BOOKING===============\n\n");
            for(i=0; i<n; i++)
            {

                while (fgets(line, sizeof(line), file1) != NULL)
                {
                    count_line2++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line2>=(count_line3[i] - 11) && count_line2<=(count_line3[i]))
                    {
                        printf("%s\n", line);

                    }
                    if(count_line2 == count_line3[i])
                    {
                        break;
                    }

                }
                printf("\n");

            }  printf("\n\n==================================================\n\n");


            fclose(file1);

        }

    }

    else
    {
        printf("There is no booking confirmed yet.\n");
    }

    return 0;
}

int View_ALL_Payment_By_Tour_ID()
{
    int count_line1=0;
    int count_line2[100];
    int count_line3[100];
    int count_line4=0;
    int i=0;
    int n;
    char line[200];
    char search[20];
    int found;
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
        found=0;
        while (fgets(line, sizeof(line), file1) != NULL)
        {

            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {

                found=1;
            }

            if(found==1 && strcmp(line,"12.Booking Status: confirmed") == 0)
            {
                count_line2[i]=count_line1;
                count_line3[i]=(count_line1-11);
                i++;
                found = 0;
            }

        }
        n=i;

        fclose(file1);

    }

    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File does not exist");
    }
    else
    {
        system("cls");
        printf("==============ALL CONFIRMED BOOKING OF TOUR ID==============\n\n");
        for(i=0; i<n; i++)
        {
            rewind(file1);
            count_line4 = 0;

            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line4++;
                line[strcspn(line, "\n")] = '\0';
                if(count_line4 >= count_line3[i] && count_line4 <= count_line2[i])
                {
                    printf("%s\n", line);
                }


            }
            printf("=========================================================\n\n");
            printf("\n");

        }
        fclose(file1);

    }

    return 0;
}

int Refund_Payment()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3=0;

    char line[200];
    char search[20];
    int found=0;
    float cost;
    int confirm=0,cancel1=0,cancel2=0,pending=0;
    int refund_done=0;
    char find[30]="1.Booking ID: ";
    printf("Enter the Booking ID you want to Refund Payment = ");
    scanf("%s",search);
    strcat(find,search);


    FILE *file1;
    FILE *file2;
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
        if(found==1)
        {



            rewind(file1);

            while (fgets(line, sizeof(line), file1) != NULL)
            {

                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2 >= count_line1 &&count_line2 <= count_line1 + 11)
                {


                    if(strncmp(line,"10.Amount paid:", strlen("10.Amount paid:")) == 0)
                    {

                        sscanf(line, "10.Amount paid: %f",&cost);

                    }

                    if(strncmp(line, "11.Payment Status: refund successful",
                               strlen("11.Payment Status: refund successful")) == 0)
                    {
                        refund_done = 1;

                    }
                }

                if(count_line2==(count_line1+11))
                {

                    if(strcmp(line,"12.Booking Status: confirmed")==0)
                    {
                        confirm=1;
                    }
                    else if(strcmp(line,"12.Booking Status: canceled")==0)
                    {
                        cancel1=1;
                    }

                    else if(strcmp(line,"12.Booking Status: canceled(Before Tour)")==0)
                    {
                        cancel2=1;
                    }

                    else if(strcmp(line,"12.Booking Status: Pending")==0)
                    {
                        pending=1;
                    }
                    break;
                }
            }


            if(refund_done == 1)
            {
                printf("This booking has already been refunded.\n");
            }

            else if(cancel1==1)
            {

                system("cls");

                printf("\n===========Refund Successful===========\n\n");
                printf("Booking ID: %s\n",search);
                printf("Amount Paid : %f\n",cost);
                printf("Refund amount: %.2f\n",cost/ 2.0f);
                printf("Booking Status: canceled\n");
                printf("\n=======================================\n\n");

                file2 = fopen("Data/Booking Management_temp.txt","w");
                if(file1==NULL || file2==NULL)
                {
                    printf("File does not exist");
                }
                else
                {
                    rewind(file1);
                    while (fgets(line, sizeof(line), file1) != NULL)
                    {

                        count_line3++;
                        line[strcspn(line, "\n")] = '\0';

                        if(count_line3==(count_line1+10))
                        {

                            fprintf(file2,
                                    "11.Payment Status: refund successful( %.2f taka)\n",
                                    cost/ 2.0f);

                        }

                        else
                        {
                            fprintf(file2, "%s\n", line);
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

                }


            }

            else if(cancel2==1)
            {
                fclose(file1);
                printf("This booking had been canceled without paying . So, There is no refund.\n");
            }
            else if(pending==1)
            {
                fclose(file1);
                printf("This booking is still pending. Please cancel the booking first before requesting a refund.\n");
            }

            else if(confirm==1)
            {
                fclose(file1);
                printf("This booking is confirmed and has not been canceled. Please cancel the booking first before requesting a refund.\n");
            }

        }

        else if(found==0)
        {
            fclose(file1);
            printf("Booking ID is invalid or not existed.");
        }
    }
    return 0;
}

int cancel_by_bookID()
{
    char search[20];

    printf("Enter the Booking ID which you want to print the receipt: ");
    scanf("%s", search);
    Print_Booking_Receipt(search);
    return 0;
}


int Print_Booking_Receipt(char search[])
{
    int count_line1 = 0;
    int count_line2 = 0;

    char line[200];
    char find[30] = "1.Booking ID: ";


    strcat(find, search);

    int found = 0;
    int confirmed = 0;
    int canceled = 0;
    int pending = 0;
    int refund_done = 0;

    float refund_amount = 0.0f;

    printf("\n=============================== PRINTING BOOKING RECEIPT ===============================\n\n");

    FILE *file1;

    file1 = fopen("Data/Booking Management.txt", "r");

    if(file1 == NULL)
    {
        printf("File does not exist.\n");
        return 0;
    }


    while(fgets(line, sizeof(line), file1) != NULL)
    {
        count_line1++;

        line[strcspn(line, "\n")] = '\0';

        if(strcmp(line, find) == 0)
        {
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        fclose(file1);

        printf("\nBooking ID '%s' is not found.\n", search);

        return 0;
    }


    else if(found=1)
    {


        rewind(file1);

        count_line2 = 0;

        while(fgets(line, sizeof(line), file1) != NULL)
        {
            count_line2++;

            line[strcspn(line, "\n")] = '\0';


            if(count_line2 >= count_line1 &&
                    count_line2 <= count_line1 + 11)
            {
                if(strncmp(line,
                           "11.Payment Status: refund successful",
                           strlen("11.Payment Status: refund successful")) == 0)
                {
                    refund_done = 1;



                    sscanf(line,
                           "11.Payment Status: refund successful( %f taka)",
                           &refund_amount);
                }
            }


            if(count_line2 == count_line1 + 11)
            {
                if(strcmp(line,
                          "12.Booking Status: confirmed") == 0)
                {
                    confirmed = 1;
                }

                else if(strcmp(line,
                               "12.Booking Status: canceled") == 0)
                {
                    canceled = 1;
                }

                else if(strcmp(line,
                               "12.Booking Status: canceled(Before Tour)") == 0)
                {
                    canceled = 1;
                }

                else if(strcmp(line,
                               "12.Booking Status: Pending") == 0)
                {
                    pending = 1;
                }

                break;
            }
        }



        if(refund_done == 1)
        {
            rewind(file1);

            count_line2 = 0;

            system("cls");
            printf("=========================================\n");
            printf("          BOOKING RECEIPT\n");
            printf("=========================================\n");

            while(fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;

                line[strcspn(line, "\n")] = '\0';

                if(count_line2 >= count_line1 &&
                        count_line2 <= count_line1 + 11)
                {
                    printf("%s\n", line);
                }

                if(count_line2 == count_line1 + 11)
                {
                    break;
                }
            }

            printf("-----------------------------------------\n");
            printf("              REFUNDED\n");
            printf("-----------------------------------------\n");
            printf("Refund Amount: %.2f taka\n", refund_amount);
            printf("-----------------------------------------\n");
            printf("This booking has been refunded.\n");
            printf("=========================================\n");
        }



        else if(confirmed == 1)
        {
            rewind(file1);

            count_line2 = 0;

            system("cls");
            printf("\n=========================================\n");
            printf("          BOOKING RECEIPT\n");
            printf("=========================================\n");

            while(fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;

                line[strcspn(line, "\n")] = '\0';

                if(count_line2 >= count_line1 &&
                        count_line2 <= count_line1 + 11)
                {
                    printf("%s\n", line);
                }

                if(count_line2 == count_line1 + 11)
                {
                    break;
                }
            }

            printf("-----------------------------------------\n");
            printf("          PAYMENT COMPLETED\n");
            printf("          BOOKING CONFIRMED\n");
            printf("-----------------------------------------\n");
            printf("Thank you for your booking!\n");
            printf("=========================================\n");
        }



        else if(canceled == 1)
        {

            system("cls");
            printf("\n===========================================\n");

            printf("\n      THIS BOOKING HAS BEEN CANCELED \n");

            printf("\nA CANCELED BOOKING RECEIPT CAN'T BE PRINTED");
            printf("\n==========================================\n");
        }

        else if(pending == 1)
        {
            system("cls");
            printf("\n=======================================================\n");
            printf("\n        THIS BOOKING IS STILL PENDING \n");

            printf("  PLEASE COMPLETE THE PAYMENT TO PRINT THE RECEIPT\n");
            printf("\n========================================================\n");
        }


        fclose(file1);
    }
    return 0;
}


int Check_Payment_Status()
{
    int count_line1=0;
    int count_line2=0;
    int found=0;

    char line[200];
    char search[20];
    char find[30]="1.Booking ID: ";

    printf("Enter the Booking ID you want to check payment status = ");
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

        while(fgets(line,sizeof(line),file1)!=NULL)
        {
            count_line1++;
            line[strcspn(line,"\n")] = '\0';

            if(strcmp(line,find)==0)
            {
                found=1;
                break;
            }
        }

        if(found==1)
        {
            system("cls");

            rewind(file1);
            char cpy[80];
            count_line2=0;

            while(fgets(line,sizeof(line),file1)!=NULL)
            {
                count_line2++;
                line[strcspn(line,"\n")] = '\0';

                if(count_line2 >= count_line1 &&
                        count_line2 <= count_line1+11)
                {

                    if(strncmp(line,
                               "11.Payment Status:",
                               strlen("11.Payment Status:"))==0)
                    {
                        sscanf(line,"11.Payment Status: %[^\n]",cpy);
                        printf("\n========================================================================================\n");
                        printf("--------------------------------------- PAYMENT STATUS ----------------------------------\n\n");
                        printf("Booking ID: %s\n",search);
                        printf("Payment Status of this Booking : %s\n\n",cpy);
                        printf("------------------------------------------------------------------------------------------\n");
                        printf("==========================================================================================\n");

                        break;
                    }
                }

                if(count_line2 == count_line1+11)
                {
                    break;
                }
            }

            fclose(file1);
        }

        else if(found==0)
        {
            fclose(file1);
            printf("\nBooking ID is invalid or not existed.\n");
        }
    }

    return 0;
}




