#ifndef TOUR_PACKAGE_MANAGEMENT_H
#define TOUR_PACKAGE_MANAGEMENT_H


struct tour_package
{
    char tourID[20];
    char tourPlace[100];
    char startingLocation[100];
    char journeyBy[30];
    char tourDate[20];
    char tourDuration[30];
    char hotelType[30];
    char tourType[30];
    int tourCapacity;
    char bonus[150];
    float costPerPersonN;
    float costPerPersonP;
    float costPerCoupleN;
    float costPerCoupleP;
    float costPerForeignerN;
    float costPerForeignerP;
    char description[200];
    char Normal_Package[80];
    char Premium_Package[80];
    char category[30];
};



int TOUR_PACKAGE_MANAGEMENT();
int Add_Tour();
int Display_all_Packages();
int Search_Tour_Packages();
int Update_Tour_Packages();
int Delete_Tour_Packages();
int Tour_Categories();
void Tour_Category();
void Tour_Type();


#endif

