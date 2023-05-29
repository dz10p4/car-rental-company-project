#include <iostream>
#include <vector>

#pragma once
#include "RentalData.h"
#include "Currency.h"
#pragma endregion

class Currency;
class RentalData;

class Employee 
{
    private:    
        std::string name;
        std::string surname;
        std::string socialSecurityNumber;

    public:
        Employee(std::string name, std::string surname, std::string socialSecurityNumber, Currency wage);
        ~Employee();
        
        bool isEmployed = true;
        Currency wage;
        int numberOfCarsRented = 0;
        std::vector<RentalData*> carsRented;

        std::string getName() const;
        std::string getSurname() const;
        std::string getSocialSecurityNumber() const;
};

std::ostream& operator<<(std::ostream& os, const Employee& e);