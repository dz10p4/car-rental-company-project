#include <RentalData.h>
#include <iostream>

using namespace std;


RentalData::RentalData(Cars* crentedCar, Client* ccarUser, Employee* crentingEmployee)
{
    rentedCar = crentedCar;
    carUser = ccarUser;
    rentingEmployee = crentingEmployee;
}

RentalData::~RentalData()
{
    delete this;
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