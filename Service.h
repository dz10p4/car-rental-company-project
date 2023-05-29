#include <iostream>

#pragma once
#include "Currency.h"

class Currency;

class Service
{
    private:
        std::string serviceType;
        Currency price;
        std::string servicePeriod;
        int lengthOfService;
    public:
        Service(std::string serviceType);
        ~Service();

        std::string getServiceType();
        Currency getPrice();
        std::string getServicePeriod();
        int getLengthOfService();

        void updatePrice(Currency cprice);
        
        void modifyServicePeriod(std::string startDate);
        void modifyLengthOfService(int newLength);
        void appendServicePeriod(std::string returnDate);
};