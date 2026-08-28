#ifndef ADMIN_SETTINGS_H
#define ADMIN_SETTINGS_H





struct ADMIN
{
    char name[40];
    char pass[40];
    char role[40];
    char system[40];
};


int ADMIN_SETTINGS();
int view_admin_Information();
int change_admin_info();
int change_admin_pass();
int admin_login();
int ADMIN();

#endif
