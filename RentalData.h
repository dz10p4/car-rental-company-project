#include <iostream>

#pragma once
#include "Employee.h"
#include "Client.h"
#include "Cars.h"
#include "Currency.h"
#pragma endregion

class Cars;
class Employee;
class Client;
class Currency;

class RentalData 
{
    private:
        Cars* rentedCar;
        Client* carUser;
        Employee* rentingEmployee;
        Currency employeeWage;
        std::string rentalPeriod;

    public:
        RentalData(Cars* rentedCar, Client* carUser, Employee* rentingEmployee, Currency employeeWage, std::string startDate);
        ~RentalData();
        
        Currency incomeFromRental;
        int distanceCovered;

        void appendRentalPeriod(std::string date);

        Cars* getRentedCar();
        Client* getCarUser();
        Employee* getRentingEmployee();
        Currency getEmployeeWage();
        std::string getRentalPeriod();
};
