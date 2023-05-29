#include <iostream>
#pragma once
#include "RentalData.h"
#include "Currency.h"
#pragma endregion

class RentalData;
class Currency;

class Client 
{
    private:
        std::string name;
        std::string surname;
        std::string socialSecurityNumber;
        std::string dateOfRegistration;
    
    public:
        Client(std::string name, std::string surname, std::string socialSecurityNumber, std::string dateOfRegistration);
        ~Client();
        bool isActive = true;
        int numberOfRentals = 0;
        int numberOfCurrentlyRentedCars = 0;
        Currency moneySpent;
        std::vector<RentalData*> rentalHistory;

        std::string getName() const;
        std::string getSurname() const;
        std::string getSocialSecutityNumber() const;
        std::string getDateOfRegistration() const;
};

std::ostream& operator<<(std::ostream& os, const Client& c);