#ifndef CUSTOMER_MANAGEMENT_H
#define CUSTOMER_MANAGEMENT_H

struct customer
{
    char name[50];
    int age;
    char address[80];
    char phone[20];
    char voterid[25];
    char email[20];
    char uniqueid[100];
    char password[30];

};
int CUSTOMER_MANAGEMENT();
int AddCustomer();
int DisplayCustomer();
int Search_Customer();
int Update_Customer_Information();
int Delete_Customer();
int Customer_Login();
int check_customer_id();
int check_tour_id();


#endif
