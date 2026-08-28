#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Search_And_Filter.h"


int View_Pending_Bookings()
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
            if(strcmp(line,"12.Booking Status: Pending") == 0)
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
            printf("============ALL PENDING BOOKINGS INFO=============\n\n");

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

            }
            printf("\n\n====================================================\n\n");

            fclose(file1);

        }

    }

    else
    {
        printf("======THERE IS NO PENDING BOOKING=========\n");
    }

    return 0;
}


int View_Cancelled_Bookings()
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
            if(strcmp(line,"12.Booking Status: canceled") == 0)
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
            printf("============ALL CANCELLED BOOKING INFO=============\n\n");

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

             printf("\n\n====================================================\n\n");

                fclose(file1);

            }



        }




    }

    else
    {
        printf("\n======THERE IS NO CANCELLED BOOKING=========\n");
    }

    return 0;
}


