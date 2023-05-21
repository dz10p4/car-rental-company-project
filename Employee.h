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
        Employee(string name, string surname, string socialSecurityNumber);
        ~Employee();
        
        bool isEmployed = true;
        float wage;
        int numberOfCarsRented = 0;
        RentalData** carsRented;

        string getName();
        string getSurname();
        string getSocialSecurityNumber();
};