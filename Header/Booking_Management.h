#ifndef BOOKING_MANAGEMENT_H
#define BOOKING_MANAGEMENT_H

struct booking
{
    char bookingID[20];
    char customerID[20];
    char tourID[20];
    char customerName[50];
    char bookingDate[20];
    int numberOfPeople;
    char seatNumber[50];
    char tourType[30];
    char totalCost[30];
    char paymentStatus[30];
    char bookingStatus[30];
    char TravelarType[30];
    float paidAmount[30];

};

int BOOKING_MANAGEMENT();
int Book_Tour();
int View_All_Bookings();
int Search_Booking();
int Update_Booking();
int Cancel_Booking();
int View_Booking_History();
int Cust_Book_hist();
int Tour_Book_hist();
int check_booking_id();
int cancel_booking_check();
int Select_Traveler_Type();
int Select_Tour_Type();


#endif
