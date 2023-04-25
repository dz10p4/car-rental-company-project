#include <iostream>

#include <RentalData.h>
using namespace std;

class Employees 
{    
    string name;

    string surname;

    string socialSecurityNumber;

    int numberOfCarsRented;

    RentalData** carsRented;
};