#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Tour_Package_Management.h"
int Add_Tour()
{
    FILE *file1;

    file1 = fopen("Data/Tour package Management.txt","a");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {
        printf("\n=================================== ADDING TOUR ==============================\n\n");


        struct tour_package package;
        printf("Enter Tour package info :\n\n");

        printf("1.Tour ID no = ");
        scanf(" %[^\n]",package.tourID);
        printf("2.Enter the Tour Category:\n");
        Tour_Category(package.category);
        printf("3.Tour place Name : ");
        scanf(" %[^\n]",package.tourPlace);
        printf("4. Tour Type:\n");
        Tour_Type(package.tourType);
        printf("5.Tour starting loacation : ");
        scanf(" %[^\n]",package.startingLocation);
        printf("6.Tour date : ");
        scanf(" %[^\n]",package.tourDate);
        printf("7.Transportation type : ");
        scanf(" %[^\n]",package.journeyBy);
        printf("8.Total Tour Duration : ");
        scanf(" %[^\n]",package.tourDuration);
        printf("9.Hotel type : ");
        scanf(" %[^\n]",package.hotelType);
        printf("10.Tour capacity : ");
        scanf("%d",&package.tourCapacity);
        printf("11.Tour Bonuses : ");
        scanf(" %[^\n]",package.bonus);
        printf("12.Normal package included : ");
        scanf(" %[^\n]", package.Normal_Package);
        printf("13.Premium package included : ");
        scanf(" %[^\n]", package.Premium_Package);

        printf("14.Cost per person (Normal and Premium package) : ");
        scanf(" %f  %f",&package.costPerPersonN, &package.costPerPersonP);

        printf("15.Cost per Couple (Normal and Premium package) : ");
        scanf(" %f  %f",&package.costPerCoupleN, &package.costPerCoupleP);

        printf("16.Cost per Foreign people (Normal and Premium package):");
        scanf(" %f  %f",&package.costPerForeignerN, &package.costPerForeignerP);

        printf("17.Short description of the tour: ");
        scanf(" %[^\n]", package.description);

        fprintf(file1,
                "\n1.Tour ID: %s\n"
                "2.Tour Category: %s\n"
                "3.Package Status: Available\n"
                "4.Tour Place: %s\n"
                "5.Tour Type: %s\n"
                "6.Starting Location: %s\n"
                "7.Tour Date: %s\n"
                "8.Transportation Type: %s\n"
                "9.Tour Duration: %s\n"
                "10.Hotel Type: %s\n"
                "11.Tour Capacity: %d\n"
                "12.Tour Bonuses: %s\n"
                "13.Normal package included: %s\n"
                "14.Premium package included: %s\n"
                "15.Short Description: %s\n"
                "\nCost list of the package :\n"
                "Cost Per Person (Normal and Premium package): %.2f and %.2f\n"
                "Cost Per Couple (Normal and Premium package): %.2f and %.2f\n"
                "Cost Per Foreigner (Normal and Premium package): %.2f and %.2f\n",
                package.tourID,
                package.category,
                package.tourPlace,
                package.tourType,
                package.startingLocation,
                package.tourDate,
                package.journeyBy,
                package.tourDuration,
                package.hotelType,
                package.tourCapacity,
                package.bonus,
                package.Normal_Package,
                package.Premium_Package,
                package.description,
                package.costPerPersonN,
                package.costPerPersonP,
                package.costPerCoupleN,
                package.costPerCoupleP,
                package.costPerForeignerN,
                package.costPerForeignerP);

        fclose(file1);
        printf("\n\n===================Tour package has been added successfully=======================\n");
    }
    return 0;
}


int Display_all_Packages()
{
    FILE *file1;
    char line[200];
    int count_line3=1;
    int i=1;
    file1 = fopen("Data/Tour package Management.txt","r");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {
        system("cls");
        printf("=========================================ALL TOUR PACKAGES======================================\n\n");
        while (fgets(line, sizeof(line), file1) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';
            if(i==1)
            {
                printf("\nTour No %d Package info:\n",count_line3);
            }

            else if((i%21)==1)
            {
                count_line3++;
                printf("Tour No %d Package info:\n",count_line3);
            }

            printf("%s\n", line);
            i++;
        }
        printf("\n\n================================================================================================\n\n");

        fclose(file1);

    }
}

int Search_Tour_Packages()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3=1;
    int i=1;
    char line[200];
    char search[20];
    int found=0;
    char find[30]="1.Tour ID: ";
    printf("Enter the Tour ID you want to Find = ");
    scanf("%s",search);
    strcat(find,search);
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
            system("cls");
            printf("======================================TOUR PACKAGE INFO=====================================\n\n");


            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=count_line1 && count_line2<=(count_line1 + 19))
                {
                    printf("%s\n", line);

                }
                if(count_line2 == count_line1 + 19)
                {
                    break;
                }

            }
            printf("\n\n============================================================================================\n\n");


            fclose(file1);

        }

    }

    else
    {
        printf("\nGiven tour ID is Invalid or Not exist");
    }

}

int Update_Tour_Packages()
{
    int count_line1=0;
    int count_line2=0;
    int found =0;
    char line[200];
    char search[20];
    char find[30]="1.Tour ID: ";
    printf("Enter the Tour ID you want to update = ");
    scanf("%s",search);
    strcat(find,search);
    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Tour package Management.txt","r");
    file2 = fopen("Data/Tour package Management_temp.txt","w");
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

        if(found == 1)
        {
            system("cls");
            printf("\n================================= UPDATE TOUR INFO================================\n\n");


            rewind(file1);
            while (fgets(line, sizeof(line), file1) != NULL)
            {

                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2==count_line1)
                {

                    struct tour_package package;
                    printf("Enter Tour package info :\n\n");

                    printf("1.Enter the Tour Category:\n");
                    Tour_Category(package.category);
                    printf("2.Tour place Name : ");
                    scanf(" %[^\n]",package.tourPlace);
                    printf("3. Tour Type:\n");
                    Tour_Type(package.tourType);
                    printf("4.Tour starting loacation : ");
                    scanf(" %[^\n]",package.startingLocation);
                    printf("5.Tour date : ");
                    scanf(" %[^\n]",package.tourDate);
                    printf("6.Transportation type : ");
                    scanf(" %[^\n]",package.journeyBy);
                    printf("7.Total Tour Duration : ");
                    scanf(" %[^\n]",package.tourDuration);
                    printf("8.Hotel type : ");
                    scanf(" %[^\n]",package.hotelType);
                    printf("9.Tour capacity : ");
                    scanf("%d",&package.tourCapacity);
                    printf("10.Tour Bonuses : ");
                    scanf(" %[^\n]",package.bonus);
                    printf("11.Normal package included : ");
                    scanf(" %[^\n]", package.Normal_Package);
                    printf("12.Premium package included : ");
                    scanf(" %[^\n]", package.Premium_Package);

                    printf("13.Cost per person (Normal and Premium package) : ");
                    scanf(" %f  %f",&package.costPerPersonN, &package.costPerPersonP);

                    printf("14.Cost per Couple (Normal and Premium package) : ");
                    scanf(" %f  %f",&package.costPerCoupleN, &package.costPerCoupleP);

                    printf("15.Cost per Foreign people (Normal and Premium package):");
                    scanf(" %f  %f",&package.costPerForeignerN, &package.costPerForeignerP);

                    printf("16.Short description of the tour: ");
                    scanf(" %[^\n]", package.description);

                    fprintf(file2,
                            "1.Tour ID: %s\n"
                            "2.Tour Category: %s\n"
                            "3.Package Status: Available\n"
                            "4.Tour Place: %s\n"
                            "5.Tour Type: %s\n"
                            "6.Starting Location: %s\n"
                            "7.Tour Date: %s\n"
                            "8.Transportation Type: %s\n"
                            "9.Tour Duration: %s\n"
                            "10.Hotel Type: %s\n"
                            "11.Tour Capacity: %d\n"
                            "12.Tour Bonuses: %s\n"
                            "13.Normal package included: %s\n"
                            "14.Premium package included: %s\n"
                            "15.Short Description: %s\n"
                            "\nCost list of the package :\n"
                            "Cost Per Person (Normal and Premium package): %.2f and %.2f\n"
                            "Cost Per Couple (Normal and Premium package): %.2f and %.2f\n"
                            "Cost Per Foreigner (Normal and Premium package): %.2f and %.2f\n",
                            search,
                            package.category,
                            package.tourPlace,
                            package.tourType,
                            package.startingLocation,
                            package.tourDate,
                            package.journeyBy,
                            package.tourDuration,
                            package.hotelType,
                            package.tourCapacity,
                            package.bonus,
                            package.Normal_Package,
                            package.Premium_Package,
                            package.description,
                            package.costPerPersonN,
                            package.costPerPersonP,
                            package.costPerCoupleN,
                            package.costPerCoupleP,
                            package.costPerForeignerN,
                            package.costPerForeignerP);

                    printf("\n======================Tour package has been updated successfully=====================\n");
                }

                else
                {
                    if(count_line2>=count_line1 && count_line2<=(count_line1 + 19))
                    {
                        continue;
                    }

                    fprintf(file2,"%s\n", line);


                }
            }

            fclose(file1);
            fclose(file2);

            if(remove("Data/Tour package Management.txt") != 0)
            {
                printf("Failed to delete the old file.\n");
            }


            if(rename("Data/Tour package Management_temp.txt", "Data/Tour package Management.txt") != 0)
            {
                printf("Failed to rename the file.\n");
            }

        }
        else
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Tour package Management_temp.txt");
            printf("Given tour ID is Invalid or Not exist");
        }



    }
}

int  Delete_Tour_Packages()
{
    int count_line1=0;
    int count_line2=0;
    int found =0;
    char line[200];
    char search[20];
    char find[30]="1.Tour ID: ";
    printf("Enter the Tour ID you want to Delete info = ");
    scanf("%s",search);
    strcat(find,search);
    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Tour package Management.txt","r");
    file2 = fopen("Data/Tour package Management_temp.txt","w");
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

        if(found == 1)
        {

            rewind(file1);
            while (fgets(line, sizeof(line), file1) != NULL)
            {

                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2 >=count_line1 && count_line2 <=(count_line1 + 19) )
                {
                    continue;
                }

                fprintf(file2,"%s\n", line);


            }


            fclose(file1);
            fclose(file2);

            if(remove("Data/Tour package Management.txt") != 0)
            {
                printf("Failed to delete the old file.\n");
            }


            if(rename("Data/Tour package Management_temp.txt", "Data/Tour package Management.txt") != 0)
            {
                printf("Failed to rename the file.\n");
            }
            system("cls");
            printf("\n\n========================Tour ID info has been Deleted Successfully=====================\n");


        }
        else
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Tour package Management_temp.txt");
            printf("\nTour ID not found.");
        }



    }
}

int Tour_Categories()
{
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int i=0;
    int n;
    char line[200];
    int found=0;
    char tour[30]="2.Tour Category: ";
    struct tour_package package;

    printf("------------------- TOUR CATEGORIES ----------------------\n\n");

    Tour_Category(package.category);

    strcat(tour,package.category);
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
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,tour) == 0)
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

        file1 = fopen("Data/Tour package Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            system("cls");
            printf("=======================================TOUR PACKAGE INFO=================================\n\n");

            for(i=0; i<n; i++)
            {


                while (fgets(line, sizeof(line), file1) != NULL)
                {
                    count_line2++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line2>=(count_line3[i] - 1) && count_line2<=(count_line3[i] + 18))
                    {
                        printf("%s\n", line);

                    }
                    if(count_line2 == count_line3[i] + 18)
                    {
                        break;
                    }

                }
                printf("\n");
            }

            fclose(file1);
            printf("\n\n==========================================================================================\n\n");
        }

    }

    else
    {

        printf("\n============================THERE IS NO TOUR PACKAGE UNDER THIS CATEGORY========================\n\n");
    }


}

void Tour_Category(char category[])
{
    int choice;

    do
    {
        printf("\nEnter the Tour Category No you want to see the Tour info = \n");

        printf("\n1. Beach");
        printf("\n2. Hill");
        printf("\n3. Nature");
        printf("\n4. Historical");
        printf("\n5. Religious");
        printf("\n6. International");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
        case 1:
            strcpy(category, "Beach");
            break;

        case 2:
            strcpy(category, "Hill");
            break;

        case 3:
            strcpy(category, "Nature");
            break;

        case 4:
            strcpy(category, "Historical");
            break;

        case 5:
            strcpy(category, "Religious");
            break;

        case 6:
            strcpy(category, "International");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    }
    while(choice < 1 || choice > 6);
}



void Tour_Type(char type[])
{
    int choice;

    do
    {
        printf("\n1. Normal");
        printf("\n2. Premium");
        printf("\n3. Normal and Premium both");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
        case 1:
            strcpy(type, "normal");
            break;

        case 2:
            strcpy(type, "premium");
            break;

        case 3:
            strcpy(type, "normal and premium both");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    }
    while(choice < 1 || choice > 3);
}
