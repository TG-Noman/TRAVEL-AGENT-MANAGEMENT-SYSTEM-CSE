#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Customer_Management.h"

int AddCustomer()
{
    FILE *file1;

    file1 = fopen("Data/Customer Management.txt","a");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {

        printf("\n==================ADDING CUSTOMER INFO=====================\n\n");


        struct customer customer;
        printf("Enter customer info :\n\n");

        printf("Enter the customer Unique id no = ");
        scanf(" %[^\n]", customer.uniqueid);

        printf("Enter the Full Name : ");
        scanf(" %[^\n]",customer.name);
        printf("Enter the age(at least 18) : ");
        scanf("%d",&customer.age);
        while(customer.age<18)
        {
            printf("\nUnder aged .Can't be registered");
            printf("\nEnter the age again (at least 18) : ");
            scanf("%d",&customer.age);
            printf("\n");
        }
        printf("Enter the phone Number (must be 11 digit): ");
        scanf(" %[^\n]",customer.phone);
        while(strlen(customer.phone)!= 11)
        {
            printf("Your phone number don't contain 11 digit.\n");
            printf("Enter the phone again.(must be 11 digit): ");
            scanf(" %[^\n]",customer.phone);
        }

        printf("Enter the Address : ");
        scanf(" %[^\n]",customer.address);
        printf("Enter the Voter id : ");
        scanf(" %[^\n]",customer.voterid);
        printf("Enter the Email : ");
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
        printf("\n\n===========CUSTOMER INFO HAS BEEN ADDED SUCCESFULLY====================\n");
    }
    return 0;
}

int DisplayCustomer()
{
    FILE *file1;
    char line[200];
    int count_line3=1;
    int i=1;
    file1 = fopen("Data/Customer Management.txt","r");
    if(file1==NULL)
    {
        printf("File doesnot exist");
    }
    else
    {
        printf("======================= ALL CUSTOMER INFO ======================\n\n");
        while (fgets(line, sizeof(line), file1) != NULL)
        {
            if(i==1)
            {
                printf("\nCustomer %d info:\n",count_line3);
            }

            else if((i%9)==1)
            {
                count_line3++;
                printf("customer %d info:\n",count_line3);
            }

            printf("%s", line);
            i++;
        }
        printf("\n==================================================================\n\n");

        fclose(file1);

    }
    return 0;
}


int Search_Customer()
{
    int count_line1=0;
    int count_line2=0;
    char line[200];
    char search[20];
    char find[30]="2.Unique ID: ";
    int found=0;
    printf("Enter the ID you want to search = ");
    scanf("%s",search);
    strcat(find,search);
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
            system("cls");
            printf("==================SERCEHRD CUSTOMER INFO======================\n\n");
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
            printf("\n\n===============================================================\n");
            fclose(file1);

        }

    }
    else
    {
        printf("\nCustomer not found or does not exist.");
    }
    return 0;
}


int Update_Customer_Information()
{
    int count_line1=0;
    int count_line2=0;
    int found =0;
    char line[200];
    char search[20];
    char find[30]="2.Unique ID: ";
    printf("Enter the ID you want to update info = ");
    scanf("%s",search);
    strcat(find,search);
    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Customer Management.txt","r");
    file2 = fopen("Data/Customer_Management_temp.txt","w");
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
            printf("\n\n=============UPDATING CUSTOMER INFO===============\n\n");
            rewind(file1);
            while (fgets(line, sizeof(line), file1) != NULL)
            {

                count_line2++;
                line[strcspn(line, "\n")] = '\0';

                if(count_line2==(count_line1 - 2) )
                {

                    struct customer customer;
                    printf("Enter customer info :\n");

                    printf("Enter the Full Name : ");
                    scanf(" %[^\n]",customer.name);
                    printf("Enter the age(at least 18) : ");
                    scanf("%d",&customer.age);
                    while(customer.age<18)
                    {
                        printf("\nUnder aged .Can't be registered");
                        printf("\nEnter the age again (at least 18) : ");
                        scanf("%d",&customer.age);
                        printf("\n");
                    }

                    printf("Enter the phone : ");
                    scanf(" %[^\n]",customer.phone);
                    while(strlen(customer.phone)!= 11)
                    {
                        printf("Your phone number don't contain 11 digit.\n");
                        printf("Enter the phone again.(must be 11 digit): ");
                        scanf(" %[^\n]",customer.phone);
                    }
                    printf("Enter the Address : ");
                    scanf(" %[^\n]",customer.address);
                    printf("Enter the Voter id : ");
                    scanf(" %[^\n]",customer.voterid);
                    printf("Enter the Email : ");
                    scanf(" %[^\n]",customer.email);

                    printf("\nPassword  must contain 4 character.\n");
                    printf("Enter that password : ");
                    scanf(" %[^\n]",customer.password);
                    while(strlen(customer.password)!= 4)
                    {
                        printf("Given password does not contain 4 character.Enter again (must be 4 character): ");
                        scanf(" %[^\n]",customer.password);
                    }

                    fprintf(file2,"\n1.Name: %s\n2.Unique ID: %s\n3.Age: %d\n4.Phone Number: %s\n5.Address: %s\n6.Voter ID: %s\n7.Email: %s\n8.Password: %s\n",customer.name,search,customer.age,customer.phone,customer.address,customer.voterid,customer.email,customer.password);

                    printf("\n\n===============CUSTOMER INFO HAS BEEN UPDATED SUCCESSFULLY\n");
                }

                else
                {

                    if(count_line2 >= (count_line1-2) && count_line2 <=(count_line1+5) )
                    {
                        continue;
                    }

                    fprintf(file2,"%s\n", line);


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


        }
        else
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Customer_Management_temp.txt");
            printf("Customer not found.");
        }



    }
    return 0;
}

int Delete_Customer()
{
    int count_line1=0;
    int count_line2=0;
    int found =0;
    char line[200];
    char search[20];
    char find[30]="2.Unique ID: ";
    printf("Enter the ID you want to Delete info = ");
    scanf("%s",search);
    strcat(find,search);
    FILE *file1;
    FILE *file2;
    file1 = fopen("Data/Customer Management.txt","r");
    file2 = fopen("Data/Customer_Management_temp.txt","w");
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

                if(count_line2 >= (count_line1-2) && count_line2 <=(count_line1+5) )
                {
                    continue;
                }

                fprintf(file2,"%s\n", line);


            }
            system("cls");
            printf("\n=============================CUSTOMER INFO HAS BEEN DELETED SUCCESFULLY==========================\n\n");

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

        }
        else
        {
            fclose(file1);
            fclose(file2);
            remove("Data/Customer_Management_temp.txt");
            printf("Customer not found.");
        }


    }
    return 0;

}





