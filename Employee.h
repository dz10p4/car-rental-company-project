#include <iostream>
#include <RentalData.h>

class Employee 
{
    private:    
        string name;
        string surname;
        string socialSecurityNumber;

    public:
        Employee(string name, string surname, string socialSecurityNumber, float wage);
        ~Employee();
        
        bool isEmployed = true;
        float wage;
        int numberOfCarsRented = 0;
        RentalData** carsRented;

        string getName();
        string getSurname();
        string getSocialSecurityNumber();
};