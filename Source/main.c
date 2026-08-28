#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "Customer_Management.h"
#include "Tour_Package_Management.h"
#include "Booking_Management.h"
#include"Payment_Management.h"
#include"Report_Statistics_Management.h"
#include"Search_And_Filter.h"
#include"Admin_Settings.h"
#include"Customer_Sign_Up.h"


int main()
{

    int prefer;

    printf("\n==================================== USER LOGIN ===============================\n\n");
    printf("1.ADMINISTRATOR LOGIN\n");
    printf("2.CUSTOMER LOGIN\n");
    printf("3.NEW CUSTOMER? SIGN UP\n");
    printf("4.EXIT\n\n");
    printf("Enter = ");
    scanf("%d",&prefer);

    system("cls");

    switch(prefer)
    {
    case 1:
        admin_login();
        break;
    case 2:
        Customer_Login();
        break;
    case 3:
        Customer_Sign_up();
        break;
    case 4:
        printf("\n-------------------------------EXIT SUCCESSFUL------------------------------\n\n");
        break;
    default:
        printf("Invalid choice ........Try again.......");
        break;
    }

    return 0;
}

int ADMIN()
{
    int choice;
    do
    {

        printf("\n=================================TRAVEL AGENT MANAGEMENT SYSTEM ==========================\n\n");
        printf("1. CUSTOMER MANAGEMENT\n");
        printf("2. TOUR PACKAGE MANAGEMENT\n");
        printf("3. BOOKING MANAGEMENT\n");
        printf("4. PAYMENT MANAGEMENT\n");
        printf("5. REPORTS & STATISTICS\n");
        printf("6. SEARCH & FILTER\n");
        printf("7. ADMIN SETTINGS\n");
        printf("8. EXIT\n\n");
        printf("\n===========================================================================================\n");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
        case 1:
            CUSTOMER_MANAGEMENT();
            break;

        case 2:
            TOUR_PACKAGE_MANAGEMENT();
            break;
        case 3:
            BOOKING_MANAGEMENT();
            break;
        case 4:
            PAYMENT_MANAGEMNET();
            break;
        case 5:
            REPORTS_AND_STATISTICS();
            break;
        case 6:
            SEARCH_AND_FILTER();
            break;
        case 7:
            ADMIN_SETTINGS();
            break;
        case 8:
            system("cls");
            printf("\n\n------------------------------------EXIT SUCCESSFUL------------------------------\n\n");
            break;
        default:
            printf("Not a valid choice");

        }

    }
    while(choice!=8);

}

int CUSTOMER_MANAGEMENT()
{
    int digit;
    printf("\n\n===================================CUSTOMER MANAGEMENT=====================================\n\n");
    printf("1.Add customer.\n");
    printf("2.View all customer.\n");
    printf("3.Search customer.\n");
    printf("4.Update customer Information.\n");
    printf("5.Delete customer\n");
    printf("6.Customer Login.\n\n");
    printf("\n===========================================================================================\n");

    printf("\nEnter the choice : ");
    scanf("%d",&digit);


    system("cls");
    switch(digit)
    {
    case 1:
        AddCustomer();
        break;
    case 2:
        DisplayCustomer();
        break;
    case 3:
        Search_Customer();
        break;
    case 4:
        Update_Customer_Information();
        break;
    case 5:
        Delete_Customer();
        break;
    case 6:
        Customer_Login();
        break;
    default :
        printf("Not a valid choice");


    }

}

int TOUR_PACKAGE_MANAGEMENT()
{

    int digit;
    printf("\n\n==================================TOUR PACKAGE MANAGEMENT===================================\n\n");
    printf("1.Add Tour Package.\n");
    printf("2.View All Tour Packages.\n");
    printf("3.Search Tour Package.\n");
    printf("4.Update Tour Package.\n");
    printf("5.Delete Tour Package\n");
    printf("6.Tour Categories.\n\n");
    printf("\n===========================================================================================\n");

    printf("\nEnter the choice : ");
    scanf("%d",&digit);
    printf("\n");

    system("cls");

    switch(digit)
    {
    case 1:
        Add_Tour();
        break;
    case 2:
        Display_all_Packages();
        break;
    case 3:
        Search_Tour_Packages();
        break;
    case 4:
        Update_Tour_Packages();
        break;
    case 5:
        Delete_Tour_Packages();
        break;
    case 6:
        Tour_Categories();
        break;
    default :
        printf("Not a valid choice");


    }
}


int BOOKING_MANAGEMENT()
{
    int choice;

    printf("\n\n===================================BOOKING MANAGEMENT======================================\n\n");

    printf("1. Book a Tour\n");
    printf("2. View All Bookings\n");
    printf("3. Search Booking\n");
    printf("4. Update Booking\n");
    printf("5. Cancel Booking\n");
    printf("6. View Booking History\n");
    printf("7. Exit\n\n");
    printf("\n===========================================================================================\n");

    printf("\nEnter the choice : ");
    scanf("%d", &choice);

    system("cls");

    switch(choice)
    {
    case 1:
        Book_Tour();
        break;

    case 2:
        View_All_Bookings();
        break;

    case 3:
        Search_Booking();
        break;

    case 4:
        Update_Booking();
        break;

    case 5:
        cancel_booking_check();
        break;

    case 6:
        View_Booking_History();
        break;


    case 7:
        printf("Exit from Booking Management.\n");
        break;

    default:
        printf("Not a valid choice.\n");
    }
}

int PAYMENT_MANAGEMNET()
{
    int digit;

    printf("\n\n==========================================PAYMENT MANAGEMENT================================\n\n");
    printf("1. Calculate Total Cost\n");
    printf("2. Make Payment\n");
    printf("3. View Payment History\n");
    printf("4. Refund Payment\n");
    printf("5. Print Booking Receipt\n");
    printf("6. Check Payment Status\n");
    printf("7. Exit\n\n");

    printf("\n===========================================================================================\n");

    printf("\nEnter the choice : ");
    scanf("%d",&digit);

    system("cls");

    switch(digit)
    {
    case 1:
        Calculate_Total_Cost();
        break;

    case 2:
        Make_Payment();
        break;

    case 3:
        View_Payment_History();
        break;

    case 4:
        Refund_Payment();
        break;

    case 5:
        cancel_by_bookID();
        break;

    case 6:
        Check_Payment_Status();
        break;
    case 7:
        printf("Exit from payment Management.............\n");
        break;

    default:
        printf("Not a valid choice");
    }

}

int REPORTS_AND_STATISTICS()
{
    int choice;

    printf("\n\n=====================================REPORTS AND STATISTICS================================\n");
    printf("1. Total Booking Statistics.\n");
    printf("2. Payment Statistics.\n");
    printf("3. Tour Booking Report.\n");
    printf("4.Back to Admin Menu...........\n\n");
    printf("\nEnter your choice: ");
    printf("\n===========================================================================================\n");

    scanf("%d", &choice);

    system("cls");

    switch(choice)
    {
    case 1:
        Total_Booking_Statistics();
        break;

    case 2:
        Payment_Statistics();
        break;

    case 3:
        Tour_Booking_Report();
        break;
    case 4:
        printf("\nReturning to Admin Menu...........\n");


    default:
        printf("Invalid choice! Please try again.\n");
    }

    return 0;

}


int SEARCH_AND_FILTER()
{
    int choice;
    do
    {
        printf("\n\n--------------------------------------\n");
        printf("           SEARCH & FILTER            \n");
        printf("--------------------------------------\n");
        printf("What related search you want to do?\n");
        printf("1. Customer Related.\n");
        printf("2. Booking Related.\n");
        printf("3. Tour related.\n");
        printf("4.Return to Admin Menu.\n");
        printf("--------------------------------------\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        system("cls");

        switch(choice)
        {
        case 1:
            customer_related();
            break;

        case 2:
            booking_related();
            break;

        case 3:
            tour_related();
            break;
        case 4:
            printf("\nReturning to Admin Menu...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    }
    while(choice!=4);

    return 0;
}

int customer_related()
{
    int choice;
    printf("\n---------CUSTOMER RELATED SEARCHES---------\n\n");
    printf("1.Specific Customer information.\n");
    printf("2.All Customer Information.\n\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    printf("\n");

    system("cls");

    switch(choice)
    {
    case 1:
        Search_Customer();
        break;
    case 2:
        DisplayCustomer();
        break;
    default:
        printf("Invalid choice. Please try again.\n");

    }

}

int tour_related()
{
    int choice;
    printf("\n---------TOUR RELATED SEARCHES---------\n\n");
    printf("1.Specific Tour Package Details.\n");
    printf("2.All Tour Package Details.\n\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    system("cls");

    switch(choice)
    {
    case 1:
        Search_Tour_Packages();
        break;
    case 2:
        Display_all_Packages();
        break;
    default:
        printf("Invalid choice. Please try again.\n");

    }
}

int booking_related()
{
    int choice;
    printf("\n---------BOOKING RELATED SEARCHES---------\n\n");

    printf("1.Specific Booking Details.\n");
    printf("2.Customer Booking Details.\n");
    printf("3.Tour ID Booking Details.\n");
    printf("4.All Booking Details.\n");
    printf("5.Confirmed Booking details.\n");
    printf("6.Pending Booking details.\n");
    printf("7.Canceled Booking details.\n");
    printf("8.Check Payment Status.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    printf("\n");

    system("cls");

    switch(choice)
    {
    case 1:
        Search_Booking();
        break;
    case 2:
        Cust_Book_hist();
        break;
    case 3:
        Tour_Book_hist();
        break;
    case 4:
        View_All_Bookings();
        break;
    case 5:
        View_All_Payment_Records();
        break;
    case 6:
        View_Pending_Bookings();
        break;
    case 7:
        View_Cancelled_Bookings();
        break;
    case 8:
        Check_Payment_Status();
        break;
    default:
        printf("Invalid choice. Please try again.\n");

    }
}

int ADMIN_SETTINGS()
{
    int prefer;

    printf("\n======================\n");
    printf("     ADMIN SETTINGS     \n");
    printf("======================\n\n");
    printf("1.View Admin Information.\n");
    printf("2.Add or Change Admin Information.\n");
    printf("3.Change Admin Password.\n");
    printf("4.Back To Admin Menu.\n\n");
    printf("Enter your choice: ");
    scanf("%d",&prefer);
    printf("\n");

    system("cls");

    switch(prefer)
    {

    case 1:
        view_admin_Information();
        break;

    case 2:
        change_admin_info();
        break;

    case 3:
        change_admin_pass();
        break;
    case 4:
        printf("\nReturning to Admin Menu......\n\n");
        break;

    default:
        printf("Invalid choice. Please try again.\n");
    }
}





