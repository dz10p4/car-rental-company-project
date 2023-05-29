#include <iostream>

#pragma once
#include <vector>
#include "RentalData.h"
#include "Currency.h"
#pragma endregion

class RentalData;
class Service;
class Currency;

class Cars 
{
    private:
        std::string make;
        std::string model;
        std::string year;
        std::string numberPlate;
        Currency pricePerDay;
        
    public:
        Cars(std::string make, std::string model, std::string year, std::string numberPlate);
        ~Cars();
        bool readyForRental = true;
        bool isRented = false;

        int mileage;
        int numberOfDaysInService = 0;
        int numberOfRentals = 0;
        int numberOfServices = 0;
        Currency moneyMade;

        void setPricePerDay(Currency price);
        Currency getPricePerDay() const;

        std::vector<RentalData*> rentalHistory;
        std::vector<Service*> serviceHistory;

        std::string getMake() const;
        std::string getModel() const;
        std::string getYear() const;
        std::string getNumberPlate() const;
};

std::ostream& operator<<(std::ostream& os, const Cars& c);