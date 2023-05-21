#include <CarRentalCompany.h>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;


CarRentalCompany::CarRentalCompany(string name)
{
    this->companyName = name;
}

CarRentalCompany::~CarRentalCompany()
{
    delete this;
}

string CarRentalCompany::getCompanyName()
{
    return companyName;
}
int CarRentalCompany::getCarFleetSize()
{
    return carFleetSize;
}
int CarRentalCompany::getNumberOfEmployees()
{
    return numberOfEmployees;
}
int CarRentalCompany::getNumberOfClients()
{
    return numberOfClients;
}
float CarRentalCompany::getIncome()
{
    return income;
}
float CarRentalCompany::getCosts()
{
    return costs;
}
Cars** CarRentalCompany::getCarArray()
{
    return fleet;
}
Client** CarRentalCompany::getClientArray()
{
    return clients;
}
Employee** CarRentalCompany::getEmployeeArray()
{
    return employees;
}

void CarRentalCompany::addVehicle(string make, string model, string year, string numberPlate, float initialMileage, float pricePerDay)
{
    fleet[carFleetSize] = new Cars(make, model, year, numberPlate);
    fleet[carFleetSize]->mileage = initialMileage;
    fleet[carFleetSize]->pricePerDay = pricePerDay;
}
void CarRentalCompany::retireVehicle(Cars* car)
{
    car->readyForRental = false;
}
void CarRentalCompany::rentVehicle(Cars* rentedCar, Employee* rentingEmployee, Client* rentingClient, string rentalDate)
{
    if(!rentedCar->readyForRental)
    {
        cout<<"It is not possible to rent that car"<<endl;
        return;
    }
    if(!rentingEmployee->isEmployed)
    {
        cout<<"That employee doesn't have access to rent cars"<<endl;
        return;
    }
    if(!rentingClient->isActive)
    {
        cout<<"This client is not allowed to borrow vehicles"<<endl;
        return;
    }
    
    rentedCar->isRented = true;
    rentedCar->readyForRental = false;
    rentedCar->rentalHistory[rentedCar->numberOfRentals] = new RentalData(rentedCar, rentingClient, rentingEmployee);
}
void CarRentalCompany::returnVehicle(Cars* car, int serviceLength, float addedMileage)
{
    if(!car->isRented)
    {
        cout<<"It's not possible to return the car"<<endl;
        return;
    }

    car->mileage += addedMileage;
    car->rentalHistory[car->numberOfRentals]->distanceCovered = addedMileage;

    stringstream startDate(car->rentalHistory[car->numberOfRentals]->getRentalPeriod());

    struct tm date = {0, 0, 0};
    string inp;
    getline(startDate, inp, '.');

    date.tm_mday = stoi(inp);

    getline(startDate, inp, '.');

    date.tm_mon = stoi(inp)-1;

    getline(startDate, inp, '.');

    date.tm_year = stoi(inp) - 1900;

    time_t date_seconds = mktime( &date ) + (serviceLength * 24 * 60 * 60) ;

    date = *localtime( &date_seconds );

    car->rentalHistory[car->numberOfRentals]->getRentalPeriod() = car->rentalHistory[car->numberOfRentals]->getRentalPeriod() + " - " +to_string(date.tm_mday)+ "." +to_string(date.tm_mon + 1) + "." + to_string(date.tm_year);

    car->rentalHistory[car->numberOfRentals]->incomeFromRental += car->pricePerDay * serviceLength;

    car->numberOfRentals++;
}


Cars* CarRentalCompany::findByPlates(string numberPlates)
{
    for(int i=0 ; i<carFleetSize ; i++)
    {
        if(fleet[i]->getNumberPlate() == numberPlates)return fleet[i];
    }
    cout<<"No cars with such number plate found"<<endl;
    return nullptr;
}

void CarRentalCompany::sendCarForService(Cars* car, string serviceType, string sendDate)
{

}
void CarRentalCompany::returnCarFromService(Cars* car, float cost, string returnDate)
{

}
Service** CarRentalCompany::getServiceHistoryOfCar(Cars* car)
{

}