#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#include"Customer_Sign_Up.h"
#include"Customer_Management.h"
#include"Booking_Management.h"
#include"Customer_Login.h"
int Customer_Sign_up()
{
    system("cls");
    printf("=======================  WELCOME TO CUSTOMER SIGNUP  =============================\n\n");

    printf("To complete the Sign up ,you are Kindly requested to Fill up the the Answer : \n\n");

    FILE *file1;

    file1 = fopen("Data/Customer Management.txt","a");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {


        struct customer customer;
        printf("Please,Fill up Your info :\n\n");

        printf("Enter a ID for Yourself = ");
        scanf(" %[^\n]",customer.uniqueid);

        while(check_customer_id(customer.uniqueid) == 1)
        {
            printf("\n-------This ID is not available.Enter a new one....--------\n\n");


            printf("Enter a ID for Yourself = ");
            scanf(" %[^\n]",customer.uniqueid);
        }


        printf("Enter Your Full Name : ");
        scanf(" %[^\n]",customer.name);
        printf("Enter Your age(at least 18) : ");
        scanf("%d",&customer.age);
        while(customer.age<18)
        {
            printf("\nUnder aged .Can't be registered");
            printf("\nEnter Your age again (at least 18) : ");
            scanf("%d",&customer.age);
            printf("\n");
        }
        printf("Enter Your phone Number (must be 11 digit): ");
        scanf(" %[^\n]",customer.phone);
        while(strlen(customer.phone)!= 11)
        {
            printf("Your phone number don't contain 11 digit.\n");
            printf("Enter the phone again.(must be 11 digit): ");
            scanf(" %[^\n]",customer.phone);
        }

        printf("Enter Your Address : ");
        scanf(" %[^\n]",customer.address);
        printf("Enter Your Voter id : ");
        scanf(" %[^\n]",customer.voterid);
        printf("Enter Your Email : ");
        scanf(" %[^\n]",customer.email);
        printf("\nPassword  must contain 4 character.\n");
        printf("Enter the password : ");
        scanf(" %[^\n]",customer.password);
        while(strlen(customer.password)!= 4)
        {
            printf("Given password does not contain 4 character.Enter again (must be 4 character): ");
            scanf(" %[^\n]",customer.password);
        }

        fprintf(file1,"\n1.Name: %s\n2.Unique ID: %s\n3.Age: %d\n4.Phone Number: %s\n5.Address: %s\n6.Voter ID: %s\n7.Email: %s\n8.Password: %s\n",customer.name,customer.uniqueid,customer.age,customer.phone,customer.address,customer.voterid,customer.email,customer.password);


        fclose(file1);
        printf("\n========================SIGN UP COMPLETED=========================\n");

        int pref;
        printf("\n\nWant to visit the CUSTOMER MENU?\n");
        printf("1.YES\n");
        printf("2.NO\n\n");
        printf("Enter your Choice: ");
        scanf("%d",&pref);
        switch(pref)
        {
        case 1:
            Customer_Login();
            break;
        case 2:
            printf("\nEXIT COMPLETED.........\n");
            break;
        default:
            printf("Invalid choice........");

        }


    }
    return 0;
}


