#include <iostream>

#include <RentalData.h>

using namespace std;

class Cars 
{
    string make;

    string model;

    string numberPlate;

    bool inService;

    bool isRented;

    int mileage;

    int numberOfDaysInService;

    int numberOfRentals;

    int moneyMade;

    RentalData** carHistory;
    
};