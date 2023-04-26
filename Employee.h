#include <iostream>
#include <RentalData.h>
using namespace std;

class Employee 
{
    private:    
        string name;
        string surname;
        string socialSecurityNumber;

    public:
        bool isEmployed = true;
        float wage;
        int numberOfCarsRented = 0;
        RentalData** carsRented;

        string getName();
        string getSurname();
        string getSocialSecurityNumber();
};