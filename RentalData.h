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

        string rentalPeriod;

    public:
        RentalData(Cars* rentedCar, Client* carUser, Employee* rentingEmployee);
        ~RentalData();
        
        float incomeFromRental;
        float distanceCovered;


        Cars* getRentedCar();
        Client* getCarUser();
        Employee* getRentingEmployee();

        string getRentalPeriod();
};