#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Report_Statistics_Management.h"

int Total_Booking_Statistics()
{

    FILE *file1;
    char line[200];
    int count_book_id=0,confirm=0,cancel=0,pending=0;
    file1 = fopen("Data/Booking Management.txt","r");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {

        while (fgets(line, sizeof(line), file1) != NULL)
        {
            line[strcspn(line, "\n")] = '\0';


            if (strncmp(line, "1.Booking ID:", strlen("1.Booking ID:")) == 0)
            {
                count_book_id++;
            }

            else if(strcmp(line,"12.Booking Status: confirmed")==0)
            {
                confirm++;
            }
            else if(strcmp(line,"12.Booking Status: canceled")==0 || strcmp(line,"12.Booking Status: canceled(Before Tour)")==0)
            {
                cancel++;
            }
            else if(strcmp(line,"12.Booking Status: Pending")==0)
            {
                pending++;
            }
        }

        fclose(file1);
        printf("\n========================= BOOKING STATISTICS =====================\n\n");
        printf("Total Bookings     : %d\n",count_book_id);
        printf("Confirmed Bookings : %d\n",confirm);
        printf("Pending Bookings   : %d\n",pending);
        printf("Canceled Bookings  : %d\n",cancel);
        printf("\n\n==================================================================\n\n");

    }
    return 0;
}

int Tour_Booking_Report()
{

    char line[200];
    char search[20];
    int found=0;
    int confirm=0;
    int booking=0;
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


            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                found=1;
                booking=1;
            }

            if(booking==1 && strcmp(line,"12.Booking Status: confirmed") == 0)
            {
                confirm++;
                booking=0;
            }

            if(booking==1 && strcmp(line,"12.Booking Status: Pending") == 0)
            {
                booking=0;
            }

            if(booking==1 && strcmp(line,"12.Booking Status: canceled") == 0)
            {
                booking=0;
            }

            if(booking==1 && strcmp(line,"12.Booking Status: canceled(Before Tour)") == 0)
            {
                booking=0;
            }

        }
        fclose(file1);


    }

    if(found==1)
    {
        system("cls");
        printf("\n========================= TOUR BOOKING STATISTICS =====================\n\n");
        printf("Tour ID : %s\n\n",search);
        printf("Confirmed/Paid Bookings: %d\n",confirm);

        if(confirm==0)
        {
            printf("No confirmed/paid bookings found for this tour.\n");
        }

        printf("\n=========================================================================\n\n");
    }

    else
    {
        printf("\nTour ID not found.\n");
    }

    return 0;
}

int Payment_Statistics()
{
    int count_line1=0;
    int count_line2=0;
    int refund_com[50];
    int refund_pen;
    int pend;
    float sum=0,sum1=0,ref_sum=0,sum2=0;
    int paid[50];
    int i=0,j=0,k=0,l=0;
    int n1,n2;
    int m,t;
    char line[200];


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

            if(strcmp(line,"11.Payment Status: Pending") == 0)
            {
                i++;
                pend=i;

            }

            else if(strcmp(line,"11.Payment Status: Half of the amount will be refunded soon.") == 0)
            {
                j++;
                refund_pen=j;

            }

            else if(strncmp(line,"11.Payment Status: paid",strlen("11.Payment Status: paid")) == 0)
            {

                paid[k]=count_line1;
                k++;
                n1=k;

            }


            else if(strncmp(line,"11.Payment Status: refund successful",strlen("11.Payment Status: refund successful")) == 0)
            {
                refund_com[l]=count_line1;
                l++;
                n2=l;

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
        for(m=0; m<n1; m++)
        {

            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=(paid[m] - 1) && count_line2<=paid[m])
                {
                    sscanf(line, "10.Amount paid: %f", &sum);

                    sum1 = sum1 + sum;
                }
                if(count_line2==paid[m])
                {
                    break;
                }

            }

        }

        rewind(file1);

        count_line2=0;
        sum=0;
        for(t=0; t<n2; t++)
        {

            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=(refund_com[t]) && count_line2<=refund_com[t]+1)
                {
                    sscanf(line, "11.Payment Status: refund successful( %f taka)", &sum);

                    ref_sum = sum2 + sum;
                }
                if(count_line2==refund_com[t])
                {
                    break;
                }

            }

        }


        fclose(file1);

    }

    printf("\n");
    printf("\n============================================\n");
    printf("             PAYMENT STATISTICS\n");
    printf("============================================\n\n");

    printf("Total Paid Amount          : %.2f Taka\n",sum1+ref_sum);
    printf("Total Refunded Amount     : %.2f Taka\n",ref_sum);
    printf("Net Revenue               : %.2f Taka\n",sum1);
    printf("Completed Payments        : %d\n",n1);
    printf("Unpaid/Pending Bookings   : %d\n",pend);
    printf("Refund Payments Completed : %d\n",n2);
    printf("Refund Payments Left      : %d\n",refund_pen);

    printf("\n");
    printf("============================================\n");


    return 0;


}
