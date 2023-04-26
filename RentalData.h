#include <iostream>

#pragma once
#include <Employee.h>
#include <Client.h>
#include <Cars.h>
#pragma endregion

using namespace std;

class RentalData 
{
    private:
        Cars* rentedCar;
        Client* carUser;
        Employee* rentingEmployee;

        float incomeFromRental;
        float distanceCovered;

        string rentalPeriod;

    public:
        Cars* getRentedCar();
        Client* getCarUser();
        Employee* getRentingEmployee();

        float getIncomeFromRental();
        float getDistanceCovered();

        string getRentalPeriod();
        string getStatus();
};