#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Admin_Settings.h"


int admin_login()
{
    printf("\n===============================ADMIN LOGIN===============================\n\n");

    char line[200];
    char pass_check[50]="4.Password: ";
    char pass[30];
    int found=0;

    printf("\nEnter The ADMIN Password: ");
    scanf(" %[^\n]",pass);
    strcat(pass_check,pass);

    FILE *file1;
    file1=fopen("Data/Admin Info.txt","r");

    if(file1==NULL)
    {
        printf("File doesn't exist");
    }

    else
    {
        while(fgets(line,sizeof(line),file1)!=NULL)
        {
            line[strcspn(line, "\n")] = '\0';

            if(strcmp(line,pass_check)==0)
            {
                found=1;
                break;
            }
        }
        fclose(file1);

        if(found==1)
        {
            system("cls");
            ADMIN();
        }
        else
        {
            printf("Password is incorrect.Please try again.....\n\n");
        }
    }
    printf("\n================================================================================\n\n");

    return 0;
}


int change_admin_info()
{
    FILE *file1;

    file1 = fopen("Data/Admin Info.txt","w");
    if(file1==NULL)
    {
        printf("File doesn't exist");
    }

    else
    {
        struct ADMIN admin;

        printf("\n============================CHANGING ADMIN INFO=============================\n");
        printf("Enter Admin Name : ");
        scanf(" %[^\n]", admin.name);

        printf("Enter the Role you are in : ");
        scanf(" %[^\n]", admin.role);

        printf("Enter the system Name you are handling : ");
        scanf(" %[^\n]", admin.system);

        printf("Enter the password : ");
        scanf(" %[^\n]", admin.pass);

        fprintf(file1,"1.Admin Name: %s\n2.Admin Role: %s\n3.System: %s\n4.Password: %s\n", admin.name, admin.role, admin.system, admin.pass);

        fclose(file1);
    }
    printf("\n=============================================================================\n\n");


    return 0;
}

int view_admin_Information()
{
    char line[200];
    FILE *file1;
    file1=fopen("Data/Admin Info.txt","r");
    if(file1==NULL)
    {
        printf("File doesn't exist");
    }

    else
    {
        printf("==========================ADMIN INFO==========================\n\n");
        while(fgets(line,sizeof(line),file1)!=NULL)
        {
            printf("%s",line);
        }
        fclose(file1);
    }
    printf("\n\n==============================================================\n\n");
    return 0;
}

int change_admin_pass()
{

    char line[200];
    char old_pass[50]="4.Password: ";
    char pass[30];
    char new_pass[50]="4.Password: ";
    char pass2[30];
    char pass3[30];
    int similar=0;
    int changed=0;

    printf("\n========================================CHANGING ADMIN PASS =====================================\n\n");
    printf("\nPlease Enter The Present Password: ");
    scanf(" %[^\n]",pass);
    strcat(old_pass,pass);

    FILE *file1;
    file1=fopen("Data/Admin Info.txt","r");

    if(file1==NULL)
    {
        printf("File doesn't exist");
    }

    else
    {
        while(fgets(line,sizeof(line),file1)!=NULL)
        {
            line[strcspn(line, "\n")] = '\0';

            if(strcmp(line,old_pass)==0)
            {
                similar=1;
                break;
            }
        }
        fclose(file1);


        if(similar==1)
        {
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
            changed=1;


        }


        else
        {
            printf("\nPassword is incorrect. Please try again......\n\n");
        }



    }


    if(changed==1)
    {
        strcat(new_pass,pass3);

        int count_line1=0;
        FILE *file2;
        file1=fopen("Data/Admin Info.txt","r");
        file2=fopen("Data/Admin_temp.txt","w");

        if(file2==NULL)
        {
            printf("File doesn't exist");
        }

        else
        {

            while(fgets(line,sizeof(line),file1)!=NULL)
            {
                line[strcspn(line, "\n")] = '\0';
                count_line1++;
                if(count_line1==4)
                {
                    fprintf(file2,"%s\n",new_pass);

                }

                else
                {
                    fprintf(file2,"%s\n",line);
                }

            }


            printf("\n=================================ADMIN PASS CHANGED SUCCESFULLY================================\n\n");
            fclose(file1);
            fclose(file2);

            if(remove("Data/Admin Info.txt") != 0)
            {
                printf("Failed to delete the old file.\n");
            }


            if(rename("Data/Admin_temp.txt", "Data/Admin Info.txt") != 0)
            {
                printf("Failed to rename the file.\n");
            }
        }

    }
    return 0;
}



