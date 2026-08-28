#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Customer_Login.h"
#include"Customer_Management.h"
#include"Tour_Package_Management.h"
#include"Booking_Management.h"
#include"Payment_Management.h"

int Customer_Login()
{
    int right1=0,right2=0;
    char id_check[20];
    char id_cpy[50]= "2.Unique ID: ";
    char pass_copy[50]= "8.Password: ";
    char psss_check[20];
    int count_line1=0;
    printf("\n--------------------CUSTOMER LOGIN ---------------------\n");
    printf("\n------------------HELLO.DEAR CUSTOMER.------------------\n\n");
    printf("Please follow the given instruction below to login in your profile:\n\n");
    printf("Enter your Unique ID : ");
    scanf(" %[^\n]",id_check);
    strcat(id_cpy,id_check);
    int count_line2=0;
    char line[200];

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
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,id_cpy) == 0)
            {
                right1++;

                break;

            }//end if of printing the customer info

        }
        fclose(file1);

    }

    if(right1==1)
    {
        printf("Enter your Password : ");
        scanf(" %[^\n]",psss_check);

        while(strlen(psss_check)!= 4)
        {
            printf("Given password does not contain 4 character.Enter again (must be 4 character) : ");
            scanf(" %[^\n]",psss_check);
        }

        strcat(pass_copy,psss_check);

        file1 = fopen("Data/Customer Management.txt","r");
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

                if(count_line2>=(count_line1 - 2) && count_line2<=(count_line1 + 6))
                {

                    if(strcmp(line,pass_copy) == 0)
                    {
                        right2++;
                        break;
                    }


                }

            }

            fclose(file1);

        }

        if(right2==0)
        {
            printf("\nGiven Password is wrong.\n");
        }


    }

    if(right1==0)
    {
        printf("\nGiven Unique ID is wrong.\n");
    }



    if(right1==1 && right2==1)

    {
        printf("=================================CUSTOMER LOGIN SUCCESSFUL============================\n\n");
        system("cls");
        Customer_Menu(id_check,count_line2);

    }

    else
    {
        printf("==================LOGIN UNSUCCESSFUL.PLEASE TRY AGIAN=================\n");
    }
    return 0;
}


int Customer_Menu(char customer_ID[],int count)
{
    system("cls");
    int choice=0;

    do
    {
        printf("\n================== CUSTOMER MENU =================\n\n");

        printf("1. View My Profile\n");
        printf("2. View My Bookings\n");
        printf("3. View ALL Tour packages\n");
        printf("4. Search Tour Packages\n");
        printf("5. Book a tour\n");
        printf("6. Make Payment\n");
        printf("7. View My Payment Status\n");
        printf("8. Print My Booking Receipt\n");
        printf("9. Cancel My Booking\n");
        printf("10. Change My Password\n");
        printf("11.Logout\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        system("cls");

        switch(choice)
        {
        case 1:
            view_my_profile(customer_ID);
            break;
        case 2:
            view_my_booking(customer_ID);
            break;
        case 3:
            Display_all_Packages();
            break;
        case 4:
            Search_Tour_Packages();
            break;
        case 5:
            customer_book(customer_ID);
            break;
        case 6:
            payment_by_customer(customer_ID);
            break;

        case 7:
            view_my_payment_status(customer_ID);
            break;
        case 8:
            print_my_booking_receipt(customer_ID);
            break;
        case 9:
            cancel_my_booking(customer_ID);
            break;
        case 10:
            change_my_pass(count);
            break;
        case 11:
            printf("Logging out..........\n");
            break;
        default:
            printf("Invalid choice....Try again.\n");
            break;


        }

    }
    while(choice!=11);
    return 0;
}

int view_my_profile(char customer_ID[])
{
    system("cls");
    int count_line1=0;
    int count_line2=0;
    char line[200];
    int found=0;
    char find[30]="2.Unique ID: ";
    strcat(find,customer_ID);
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
            count_line1++;
            line[strcspn(line, "\n")] = '\0';
            if(strcmp(line,find) == 0)
            {
                found++;
                break;

            }//end if of printing the customer info

        }
        fclose(file1);

    }

    if(found==1)
    {

        file1 = fopen("Data/Customer Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            printf("================== CUSTOMER PROFILE ==============\n\n");
            while (fgets(line, sizeof(line), file1) != NULL)
            {
                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2>=(count_line1 - 2) && count_line2<=(count_line1 + 6))
                {
                    printf("%s\n", line);

                }
                if(count_line2 == count_line1 + 6)
                {
                    break;
                }

            }
            printf("\n\n===================================================\n\n");

            fclose(file1);

        }

    }
    else
    {
        printf("\nCustomer not found or doesnot exist.");
    }
    return 0;
}

int view_my_booking(char customer_ID[])
{
    system("cls");
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int i=0;
    int n;
    char line[200];
    int found=0;
    char find[30]="2.Customer ID: ";
    strcat(find,customer_ID);
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
            printf("\n\n============================YOUR BOOKING LIST=========================\n\n");
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
            printf("\n\n=======================================================================\n\n");

            fclose(file1);

        }

    }

    else
    {
        printf("This Customer has no booking yet.\n\n");
    }
    return 0;

}

int view_my_payment_status(char customer_ID[])
{
    system("cls");
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int i=0;
    int n;
    char line[200];
    int found=0;
    char bookID[20][20];
    char payinfo[20][100];
    char find[30]="2.Customer ID: ";
    strcat(find,customer_ID);
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
        printf("\n\n==========================YOUR ALL BOOKING PAYMNET STATUS INFO====================\n\n");

        file1 = fopen("Data/Booking Management.txt","r");
        if(file1==NULL)
        {
            printf("File does not exist");
        }
        else
        {
            for(i=0; i<n; i++)
            {
                while (fgets(line, sizeof(line), file1) != NULL)
                {
                    count_line2++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line2==(count_line3[i] - 1))
                    {
                        sscanf(line,"1.Booking ID: %s",bookID[i]);
                        printf("%d.BOOKING ID: %s\n",i+1,bookID[i]);

                    }
                    else if(count_line2==(count_line3[i] + 9))
                    {
                        sscanf(line,"11.Payment Status: %[^\n]",payinfo[i]);
                        printf("Payment Status of This Booking ID: %s\n\n", payinfo[i]);


                    }

                    if(count_line2 == count_line3[i] + 11)
                    {
                        break;
                    }

                }

            }

            fclose(file1);

        }
        printf("\n=====================================================================================\n");

    }

    else
    {
        printf("\n==========YOU HAVE MADE NO BOOKING YET==========\n\n");
    }

    return 0;

}

int print_my_booking_receipt(char customer_ID[])
{
    system("cls");

    char choice[20];
    char bookID[20][20];
    int found=0;
    int check=0;
    found= finding_bookingID_by_customer_ID(customer_ID,bookID);


    if(found>=1)
    {
        printf("Enter the Booking ID Which you want to print the receipt : ");
        scanf("%s",choice);
        system("cls");

        for(int j=0; j<found; j++)
        {
            if(strcmp(bookID[j],choice)==0)
            {
                Print_Booking_Receipt(choice);

                check=1;

                break;
            }

        }

        if(check==0)
        {
            printf("\n----------------YOU HAVE ENTERED A WRONG BOOKING ID------------------\n\n");
        }


    }



    return 0;


}


int cancel_my_booking(char customer_ID[])
{
    system("cls");
    int prefer=0;
    printf("Are you sure you want to cancel your Booking ?\n");
    printf("1.Yes.\n");
    printf("2.No.\n");
    scanf("%d",&prefer);
    switch(prefer)
    {
    case 1:
        cancel_book(customer_ID);
        break;
    case 2:
        printf("Booking cancellation has been stopped.\n");
        break;
    default:
        printf("Invalid choice.Try again.......\n");
    }
    return 0;
}

int cancel_book(char customer_ID[])
{
    system("cls");
    char choice[20];
    char bookID[20][20];
    int found=0;
    int check=0;
    found= finding_bookingID_by_customer_ID(customer_ID,bookID);


    if(found>=1)
    {
        printf("Enter the Booking ID Which you want to cancel : ");
        scanf("%s",choice);
        system("cls");
        for(int j=0; j<found; j++)
        {
            if(strcmp(bookID[j],choice)==0)
            {
                Cancel_Booking(choice);

                check=1;

                break;
            }

        }

        if(check==0)
        {
            printf("\n----------------YOU HAVE ENTERED A WRONG BOOKING ID------------------\n\n");
        }


    }



    return 0;
}

int payment_by_customer(char customer_ID[])
{
    system("cls");

    char choice[20];
    char bookID[20][20];
    int found=0;
    int check=0;
    found= finding_bookingID_by_customer_ID(customer_ID,bookID);


    if(found>=1)
    {
        printf("Enter the Booking ID Which you want to Make Payment : ");
        scanf("%s",choice);
        system("cls");
        for(int j=0; j<found; j++)
        {
            if(strcmp(bookID[j],choice)==0)
            {
                Make_Payment(choice);

                check=1;

                break;
            }

        }

        if(check==0)
        {
            printf("\n----------------YOU HAVE ENTERED A WRONG BOOKING ID------------------\n\n");
        }


    }



    return 0;
}



int finding_bookingID_by_customer_ID(char customer_ID[],char bookID[][20])
{
    int count_line1=0;
    int count_line2=0;
    int count_line3[50];
    int found=0;
    int n;
    int i=0;
    char line[200];

    char find[30]="2.Customer ID: ";
    strcat(find,customer_ID);
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
        printf("\n");
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
            printf("===================== YOUR BOOKING ID'S =====================\n\n");
            for(i=0; i<n; i++)
            {

                while (fgets(line, sizeof(line), file1) != NULL)
                {
                    count_line2++;
                    line[strcspn(line, "\n")] = '\0';

                    if(count_line2==(count_line3[i] - 1))
                    {
                        sscanf(line,"1.Booking ID: %s",bookID[i]);
                        printf("%d.BOOKING ID: %s\n",i+1,bookID[i]);

                    }
                    if(count_line2 == count_line3[i])
                    {
                        break;
                    }

                }


            }
            printf("\n========================================================\n\n");

            fclose(file1);

        }

    }


    else
    {
        printf("\n------------------THIS ID HAS MADE NO BOOKING YET--------------\n\n");

    }

    return found;



}


int change_my_pass(int right2)
{
    system("cls");
    int prefer=0;
    printf("Are you you want to change your password?\n");
    printf("1.Yes.\n");
    printf("2.No.\n");
    printf("Enter your choice: ");
    scanf("%d",&prefer);
    printf("\n");



    switch(prefer)
    {

    case 1:
        system("cls");
        change_pass(right2);
        break;
    case 2:
        printf("Returning to Customer Menu...........\n");
        break;
    default:
        printf("Invalid choice.Try Again........\n");
        break;

    }
    return 0;

}

int change_pass(int count_line1)
{
    system("cls");
    char line[200];
    char new_pass[50]="8.Password: ";
    char pass2[30];
    char pass3[30];
    int count_line2=0;

    printf("\n\n=================================CHANGING PASSWORD===================================\n\n");
    printf("Enter The New Password: \n");
    scanf(" %[^\n]",pass2);

    printf("Enter Again The New Password to Confirm: ");
    scanf(" %[^\n]",pass3);

    while(strcmp(pass2,pass3)!=0)
    {
        printf("\nPassword doesn't match. Please try again.\n\n");

        printf("Enter The New Password: ");
        scanf(" %[^\n]",pass2);

        printf("Enter Again The New Password to Confirm: ");
        scanf(" %[^\n]",pass3);
    }

    strcat(new_pass,pass3);



    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Customer Management.txt","r");
    file2 = fopen("Data/Customer_Management_temp.txt","w");
    if(file1==NULL || file2==NULL)
    {
        printf("File does not exist.\n");
    }
    else
    {
        while (fgets(line, sizeof(line), file1) != NULL)
        {

            count_line2++;
            line[strcspn(line, "\n")] = '\0';

            if(count_line2==count_line1)
            {


                fprintf(file2,"%s\n",new_pass);

                printf("\n\n========================PASSWORD HAS BEEN SUCCESFULLY CHANGED=============================\n\n");
            }

            else
            {

                fprintf(file2,"%s\n", line);

            }
        }


    }

    fclose(file1);
    fclose(file2);

    if(remove("Data/Customer Management.txt") != 0)
    {
        printf("Failed to delete the old file.\n");
    }

    if(rename("Data/Customer_Management_temp.txt", "Data/Customer Management.txt") != 0)
    {
        printf("Failed to rename the file.\n");
    }


    return 0;
}

int customer_book(char customer_ID[])
{
    printf("=====================================Booking Tour========================\n\n");
    printf("Dear customer , To Book a Tour your are requested to follow the steps:\n\n ");

    FILE *file;

    file = fopen("Data/Booking Management.txt","a");
    if(file==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {
        struct booking booking;

        printf("1.Enter a Booking ID no = ");
        scanf(" %[^\n]",booking.bookingID);

        while(check_booking_id(booking.bookingID) == 1)
        {
            printf("This Booking ID is not available..Try another one.....\n\n");

            printf("1.Enter Booking ID no = ");
            scanf(" %[^\n]",booking.bookingID);

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

        printf("6.Tour Type : ");
        scanf(" %[^\n]",booking.tourType);

        printf("7.Traveler Type(person/couple/foreigner) : ");
        scanf(" %[^\n]",booking.TravelarType);

        fprintf(file,
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
                customer_ID,
                booking.tourID,
                booking.customerName,
                booking.bookingDate,
                booking.numberOfPeople,
                booking.TravelarType,
                booking.tourType);

        fclose(file);

        printf("\n================================BOOKING HAS MADE SSUCCESSFULY========================\n");
    }
    return 0;
}





