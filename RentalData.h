#include <iostream>

#pragma once
#include <Employee.h>
#include <Client.h>
#include <Cars.h>
#pragma endregion

class RentalData 
{
    private:
        Cars* rentedCar;
        Client* carUser;
        Employee* rentingEmployee;
        float employeeWage;
        string rentalPeriod;

    public:
        RentalData(Cars* rentedCar, Client* carUser, Employee* rentingEmployee, float employeeWage);
        ~RentalData();
        
        float incomeFromRental;
        float distanceCovered;


        Cars* getRentedCar();
        Client* getCarUser();
        Employee* getRentingEmployee();

        string getRentalPeriod();
};