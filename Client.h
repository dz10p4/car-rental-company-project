#include <iostream>

#include <RentalData.h>

using namespace std;

class Client 
{
    string name;

    string surname;

    string socialSecurityNumber;

    string dateOfRegistration;

    bool isActive;

    int numberOfRentals;

    int numberOfCurrentlyRentedCars;

    int moneySpent;

    Rental_Data** rentalHistory;
};