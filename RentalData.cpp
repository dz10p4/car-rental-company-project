#include "RentalData.h"
#include <iostream>

using namespace std;


RentalData::RentalData(Cars* crentedCar, Client* ccarUser, Employee* crentingEmployee, Currency cemployeeWage, string cstartDate)
{
    rentedCar = crentedCar;
    carUser = ccarUser;
    rentingEmployee = crentingEmployee;
    employeeWage = cemployeeWage;
    rentalPeriod = cstartDate;
}

RentalData::~RentalData()
{
    delete this;
}

Cars* RentalData::getRentedCar()
{
    return rentedCar;
}

Client* RentalData::getCarUser()
{
    return carUser;
}

Employee* RentalData::getRentingEmployee()
{
    return rentingEmployee;
}

string RentalData::getRentalPeriod()
{
    return rentalPeriod;
}

Currency RentalData::getEmployeeWage()
{
    return employeeWage;
}

void RentalData::appendRentalPeriod(string date)
{
    rentalPeriod += " - " + date;
}