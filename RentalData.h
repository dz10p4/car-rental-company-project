#include <iostream>

#include <Service.h>
#include <Employees.h>
#include <Cars.h>

using namespace std;

class RentalData 
{
    Cars* rentedCar;

    Client* carUser;

    Employees* rentingEmployee;

    bool servicedAfterRental;

    Service** listOfServices;

    int costOfServices;

    int incomeFromRental;

    int distanceCovered;

    string rentalPeriod;

    string status;

};