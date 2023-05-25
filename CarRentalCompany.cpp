#include <CarRentalCompany.h>
#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

int findDateDifference(string datea1, string datea2)
{
    struct tm date1, date2, *tptr;
    time_t datei1, datei2;

    time(&datei1);
    time(&datei2);

    tptr = localtime(&datei1);
    date1 = *tptr;
    tptr = localtime(&datei2);
    date2 = *tptr;

    string inp;

    stringstream startDate(datea1);

    getline(startDate, inp, '.');
    date1.tm_mday = stoi(inp);

    getline(startDate, inp, '.');
    date1.tm_mon = stoi(inp)-1;

    getline(startDate, inp, ' ');
    date1.tm_year = stoi(inp) - 1900;

    stringstream endDate(datea2);

    getline(endDate, inp, '.');
    date2.tm_mday = stoi(inp);

    getline(endDate, inp, '.');
    date2.tm_mon = stoi(inp)-1;

    getline(endDate, inp, ' ');
    date2.tm_year = stoi(inp) - 1900;

    datei1 = mktime(&date1);
    datei2 = mktime(&date2);

    return difftime(datei2,datei1)/86400;
}

string getFirstDate(string date)
{
    stringstream ss(date);
    string outp,newDate;

    getline(ss, newDate, '.');
    outp+=newDate;
    getline(ss, newDate, '.');
    outp+=newDate;
    getline(ss, newDate, ' ');
    outp+=newDate;
    return outp;
}

string getSecondDate(string date)
{
    stringstream ss(date);
    string outp,newDate;
    getline(ss,newDate, '-');
    getline(ss,newDate,' ');
    getline(ss, newDate, '.');
    outp+=newDate;
    getline(ss, newDate, '.');
    outp+=newDate;
    getline(ss, newDate, ' ');
    outp+=newDate;
    return outp;
}

int dateComparator(string first, string second)
{   
    int timeDifference = findDateDifference(first,second);
    if(timeDifference>0)return 1;
    else if(timeDifference<0) return -1;
    else return 0;
}

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
    carFleetSize++;
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
    rentedCar->rentalHistory[rentedCar->numberOfRentals] = new RentalData(rentedCar, rentingClient, rentingEmployee, rentingEmployee->wage);
    rentingEmployee->carsRented[rentingEmployee->numberOfCarsRented++] = rentedCar->rentalHistory[rentedCar->numberOfRentals];
    rentingClient->rentalHistory[rentingClient->numberOfRentals++] = rentedCar->rentalHistory[rentedCar->numberOfRentals];
    rentingClient->numberOfCurrentlyRentedCars++;
}
void CarRentalCompany::returnVehicle(Cars* car, string returnDate, float addedMileage)
{
    if(!car->isRented)
    {
        cout<<"It's not possible to return the car"<<endl;
        return;
    }

    car->mileage += addedMileage;
    car->rentalHistory[car->numberOfRentals]->distanceCovered = addedMileage;

    int serviceLength = findDateDifference(car->rentalHistory[car->numberOfRentals]->getRentalPeriod(), returnDate);

    car->numberOfDaysInService += serviceLength;
    car->rentalHistory[car->numberOfRentals]->getRentalPeriod() +=  " - " + returnDate;

    car->rentalHistory[car->numberOfRentals]->incomeFromRental += car->pricePerDay * serviceLength;

    car->rentalHistory[car->numberOfRentals]->getCarUser()->numberOfCurrentlyRentedCars--;

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
    if(car->isRented || car->readyForRental)
    {
        cout<<"You cannot send this car to service."<<endl;
        return;
    }
    Service* serviceData = new Service(serviceType);
    
    car->readyForRental = false;
    serviceData->getServicePeriod() = sendDate;
    car->serviceHistory[car->numberOfServices] = serviceData;
}
void CarRentalCompany::returnCarFromService(Cars* car, float cost, string returnDate)
{
    car->serviceHistory[car->numberOfServices]->modifyLengthOfService(findDateDifference(car->serviceHistory[car->numberOfRentals]->getServicePeriod(), returnDate));
    car->serviceHistory[car->numberOfServices]->appendServicePeriod(returnDate);
    costs += cost;
    car->numberOfServices++;
}

Service** CarRentalCompany::getServiceHistoryOfCar(Cars* car)
{
    return car->serviceHistory;
}

void CarRentalCompany::registerClient(string name, string surname, string socialSecurityNumber, string dateOfRegistration)
{
    clients[numberOfClients] = new Client(name, surname, socialSecurityNumber, dateOfRegistration);
    numberOfClients++;
}

void CarRentalCompany::removeClient(Client* client)
{
    client->isActive = false;
}

Client* CarRentalCompany::findClientBySocialSecurityNumber(string socialSecurityNumber)
{
    for(int i=0 ; i < numberOfClients ; i++)
    {
        if(clients[i]->getSocialSecutityNumber() == socialSecurityNumber)return clients[i];
    }
    cout<<"There are no clients with that social security number."<<endl;
    return nullptr;
}

void CarRentalCompany::hireEmployee(string name, string surname, string socialSecurityNumber, float wage)
{
    employees[numberOfEmployees] = new Employee(name, surname, socialSecurityNumber, wage);
    numberOfEmployees++;
}

void CarRentalCompany::fireEmployee(Employee* employee)
{
    employee->isEmployed = false;
}

void CarRentalCompany::changeWage(Employee* employee, float newWage)
{
    employee->wage = newWage;
}

Employee* CarRentalCompany::findEmployeeBySocialSecurityNumber(string socialSecurityNumber)
{
    for(int i=0 ; i < numberOfEmployees; i++)
    {
        if(employees[i]->getSocialSecurityNumber() == socialSecurityNumber)return employees[i];
    }
    cout<<"There are no employees with that social security number."<<endl;
    return nullptr;
}

RentalData** CarRentalCompany::getRentalHistoryOfClient(Client* client)
{
    return client->rentalHistory;
}

RentalData** CarRentalCompany::getRentalHistoryOfCar(Cars* car)
{
    return car->rentalHistory;
}

RentalData** CarRentalCompany::getRentalHistoryOfEmployee(Employee* employee)
{
    return employee->carsRented;
}

void CarRentalCompany::getFinancialStatisticsForPeriod(string startDate, string endDate)
{
    
}

pair<int,int> CarRentalCompany::getFinancialStatisticsOfCarForPeriod(Cars* car, string startDate, string endDate)
{
    float earnings = 0, costs = 0;
    
    for(int i=0 ; i<car->numberOfRentals ; i++)
    {
        string begginingOfRental = getFirstDate(car->rentalHistory[i]->getRentalPeriod());
        string endOfRental = getSecondDate(car->rentalHistory[i]->getRentalPeriod());

        if(dateComparator(begginingOfRental, startDate) < 1 && dateComparator(endOfRental, endDate) > -1)
        {
            earnings += findDateDifference(begginingOfRental, endOfRental) * car->pricePerDay;
        }
        else if(dateComparator(endOfRental, endDate) > -1)
        {
            earnings += findDateDifference(startDate, endOfRental) * car->pricePerDay;
        }
        else if(dateComparator(begginingOfRental, startDate) < 1)
        {
            earnings += findDateDifference(begginingOfRental ,endDate) * car->pricePerDay;
        }
    }

    for(int i=0 ; i<car->numberOfServices ; i++)
    {
        string begginingOfService = getFirstDate(car->serviceHistory[i]->getServicePeriod());
        string endOfService = getSecondDate(car->serviceHistory[i]->getServicePeriod());

        if(dateComparator(begginingOfService, startDate) < 1 && dateComparator(endOfService, endDate) > -1)
        {
            costs += car->serviceHistory[i]->getPrice();
        }
        else if(dateComparator(endOfService, endDate) > -1)
        {
            costs += car->serviceHistory[i]->getPrice();
        }
        else if(dateComparator(begginingOfService, startDate) < 1)
        {
            costs += car->serviceHistory[i]->getPrice();
        }
    }

    cout<<"The car earned "<<earnings<<" and costed "<<costs<<" so the net income from the car was "<<earnings-costs<<endl;
    return {earnings, costs};
}

pair<int,int> CarRentalCompany::getFinancialStatisticsOfClientForPeriod(Client* client, string startDate, string endDate)
{
    
}

pair<int,int> CarRentalCompany::getFinancialStatisticsOfEmployeeForPeriod(Employee* employee, string startDate, string endDate)
{
    
}

int CarRentalCompany::getMileageOfCarForPeriod(Cars* car, string startDate, string endDate)
{
    
}