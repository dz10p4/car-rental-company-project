#include "CarRentalCompany.h"
#include "Currency.h"

#include <iostream>
#include <ctime>
#include <sstream>

using namespace std;

int CarRentalCompany::findDateDifference(string datea1, string datea2)
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

int CarRentalCompany::stoif(string money)
{
    int result = 0;

    for(int i=0 ; i<money.size() ; i++)
    {
        if(money[i]=='.')continue;
        result+=money[i]-'0';
        result *= 10;
    }

    return result/10;
}

string CarRentalCompany::getFirstDate(string date)
{
    stringstream ss(date);
    string outp,newDate;

    getline(ss, newDate, '.');
    outp+=newDate + ".";
    getline(ss, newDate, '.');
    outp+=newDate + ".";
    getline(ss, newDate, ' ');
    outp+=newDate;
    return outp;
}

string CarRentalCompany::getSecondDate(string date)
{
    stringstream ss(date);
    string outp,newDate;
    getline(ss,newDate, '-');
    getline(ss,newDate,' ');
    getline(ss, newDate, '.');
    outp+=newDate + ".";
    getline(ss, newDate, '.');
    outp+=newDate + ".";
    getline(ss, newDate, ' ');
    outp+=newDate;
    return outp;
}

int CarRentalCompany::dateComparator(string first, string second)
{   
    int timeDifference = findDateDifference(first,second);
    if(timeDifference>0)return 1;
    else if(timeDifference<0) return -1;
    else return 0;
}

int CarRentalCompany::countDaysInPeriod(string period)
{
    return findDateDifference(getFirstDate(period), getSecondDate(period));
}

CarRentalCompany::CarRentalCompany(string name)
{
    this->companyName = name;
}

CarRentalCompany::~CarRentalCompany()
{
    for(auto I:fleet)
    {
        delete I;
    }

    for(auto I:clients)
    {
        delete I;
    }

    for(auto I:employees)
    {
        delete I;
    }

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
vector<Cars*> CarRentalCompany::getCarArray()
{
    return fleet;
}
vector<Client*> CarRentalCompany::getClientArray()
{
    return clients;
}
vector<Employee*> CarRentalCompany::getEmployeeArray()
{
    return employees;
}

void CarRentalCompany::addVehicle(string make, string model, string year, string numberPlate, int initialMileage, string pricePerDay)
{
    fleet.push_back(new Cars(make, model, year, numberPlate));
    fleet[carFleetSize]->mileage = initialMileage;
    fleet[carFleetSize]->setPricePerDay(Currency(pricePerDay));
    carFleetSize++;
}
void CarRentalCompany::retireVehicle(Cars* car)
{
    if(car->isRented)
    {
        cout<<"You cannot retire a rented vehicle."<<endl;
        return;
    }
    car->readyForRental = false;
}
void CarRentalCompany::rentVehicle(Cars* rentedCar, Employee* rentingEmployee, Client* rentingClient, string rentalDate)
{
    if(rentedCar == nullptr || rentingEmployee == nullptr || rentingClient == nullptr)
    {
        return;
    }
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
    rentedCar->rentalHistory.push_back(new RentalData(rentedCar, rentingClient, rentingEmployee, rentingEmployee->wage, rentalDate));
    rentingEmployee->carsRented.push_back(rentedCar->rentalHistory[rentedCar->numberOfRentals]);
    rentingEmployee->numberOfCarsRented++;
    rentingClient->rentalHistory.push_back(rentedCar->rentalHistory[rentedCar->numberOfRentals]);
    rentingClient->numberOfCurrentlyRentedCars++;
}
void CarRentalCompany::returnVehicle(Cars* car, string returnDate, int addedMileage)
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
    car->rentalHistory[car->numberOfRentals]->appendRentalPeriod(returnDate);

    car->rentalHistory[car->numberOfRentals]->incomeFromRental += car->getPricePerDay() * serviceLength;

    car->moneyMade += car->getPricePerDay() * serviceLength;
    car->rentalHistory[car->numberOfRentals]->getCarUser()->moneySpent += car->getPricePerDay() * serviceLength;

    car->rentalHistory[car->numberOfRentals]->getCarUser()->numberOfCurrentlyRentedCars--;

    car->rentalHistory[car->numberOfRentals]->getCarUser()->numberOfRentals++;
    car->isRented = false;
    car->readyForRental = true;
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

bool CarRentalCompany::checkIfThisCarIsInDatabase(string numberPlate)
{
    for(int i=0 ; i<carFleetSize ; i++)
    {
        if(fleet[i]->getNumberPlate() == numberPlate)
        return 1;
    }

    return 0;
}

void CarRentalCompany::sendCarForService(Cars* car, string serviceType, string sendDate)
{
    if(car->isRented || !car->readyForRental)
    {
        cout<<"You cannot send this car to service."<<endl;
        return;
    }
    Service* serviceData = new Service(serviceType);
    
    car->readyForRental = false;
    serviceData->modifyServicePeriod(sendDate);
    car->serviceHistory.push_back(serviceData);
}
void CarRentalCompany::returnCarFromService(Cars* car, string cost, string returnDate)
{
    car->serviceHistory[car->numberOfServices]->modifyLengthOfService(findDateDifference(car->serviceHistory[car->numberOfServices]->getServicePeriod(), returnDate));
    car->serviceHistory[car->numberOfServices]->appendServicePeriod(returnDate);
    car->serviceHistory[car->numberOfServices]->updatePrice(Currency(cost));
    car->numberOfServices++;
    car->readyForRental = true;
}

vector<Service*> CarRentalCompany::getServiceHistoryOfCar(Cars* car)
{
    return car->serviceHistory;
}

void CarRentalCompany::registerClient(string name, string surname, string socialSecurityNumber, string dateOfRegistration)
{
    clients.push_back(new Client(name, surname, socialSecurityNumber, dateOfRegistration));
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

bool CarRentalCompany::checkIfThisClientIsInDatabase(string socialSecurityNumber)
{
    for(int i=0 ; i<numberOfClients ; i++)
    {
        if(clients[i]->getSocialSecutityNumber() == socialSecurityNumber)
        return 1;
    }

    return 0;
}

void CarRentalCompany::hireEmployee(string name, string surname, string socialSecurityNumber, string wage)
{
    employees.push_back(new Employee(name, surname, socialSecurityNumber, Currency(wage)));
    numberOfEmployees++;
}

void CarRentalCompany::fireEmployee(Employee* employee)
{
    employee->isEmployed = false;
}

void CarRentalCompany::changeWage(Employee* employee, std::string newWage)
{
    employee->wage = Currency(newWage);
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

bool CarRentalCompany::checkIfThisEmployeeIsInDatabase(string socialSecurityNumber)
{
    for(int i=0 ; i<numberOfEmployees ; i++)
    {
        if(employees[i]->getSocialSecurityNumber() == socialSecurityNumber)
        return 1;
    }

    return 0;
}

vector<RentalData*> CarRentalCompany::getRentalHistoryOfClient(Client* client)
{
    return client->rentalHistory;
}

vector<RentalData*> CarRentalCompany::getRentalHistoryOfCar(Cars* car)
{
    return car->rentalHistory;
}

vector<RentalData*> CarRentalCompany::getRentalHistoryOfEmployee(Employee* employee)
{
    return employee->carsRented;
}

pair<Currency, Currency> CarRentalCompany::getFinancialStatisticsOfCarForPeriod(Cars* car, string startDate, string endDate)
{
    Currency earnings, costs;
    
    for(int i=0 ; i<car->numberOfRentals ; i++)
    {
        string begginingOfRental = getFirstDate(car->rentalHistory[i]->getRentalPeriod());
        string endOfRental = getSecondDate(car->rentalHistory[i]->getRentalPeriod());

        if(dateComparator(begginingOfRental, startDate) < 1 && dateComparator(endOfRental, endDate) > -1)
        {
            earnings += car->getPricePerDay() * findDateDifference(begginingOfRental, endOfRental) ;
        }
        else if(dateComparator(endOfRental, endDate) > -1)
        {
            earnings += car->getPricePerDay() * findDateDifference(startDate, endOfRental) ;
        }
        else if(dateComparator(begginingOfRental, startDate) < 1)
        {
            earnings += car->getPricePerDay() * findDateDifference(begginingOfRental ,endDate);
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

    cout<<"The car:\n"<<*car<<"earned "<<earnings<<" and costed "<<costs<<" so the net income from the car was "<<earnings-costs<<endl<<endl;
    return {earnings, costs};
}

pair<Currency, int> CarRentalCompany::getFinancialStatisticsOfClientForPeriod(Client* client, string startDate, string endDate)
{
    Currency earnings; 
    int rentals = 0;
    
    for(int i=0 ; i<client->numberOfRentals ; i++)
    {
        string begginingOfRental = getFirstDate(client->rentalHistory[i]->getRentalPeriod());
        string endOfRental = getSecondDate(client->rentalHistory[i]->getRentalPeriod());
        int dateDifference = countDaysInPeriod(client->rentalHistory[i]->getRentalPeriod());

        if(dateComparator(begginingOfRental, startDate) < 1 && dateComparator(endOfRental, endDate) > -1)
        {
            earnings += (client->rentalHistory[i]->incomeFromRental / dateDifference) * findDateDifference(begginingOfRental, endOfRental) ;
            rentals++;
        }
        else if(dateComparator(endOfRental, endDate) > -1)
        {
            earnings += (client->rentalHistory[i]->incomeFromRental / dateDifference) * findDateDifference(startDate, endOfRental);
            rentals++;
        }
        else if(dateComparator(begginingOfRental, startDate) < 1)
        {
            earnings += (client->rentalHistory[i]->incomeFromRental / dateDifference) * findDateDifference(begginingOfRental, endDate) ;
            rentals++;
        }
    }

    cout<<"The client:\n"<<*client<<"rented "<<rentals<<" cars and payed the company "<<earnings<<" in total"<<endl<<endl;
    return {earnings, rentals};
}

pair<Currency, Currency> CarRentalCompany::getFinancialStatisticsOfEmployeeForPeriod(Employee* employee, string startDate, string endDate)
{
    Currency earnings, wage;
    
    for(int i=0 ; i<employee->numberOfCarsRented ; i++)
    {
        string begginingOfRental = getFirstDate(employee->carsRented[i]->getRentalPeriod());
        string endOfRental = getSecondDate(employee->carsRented[i]->getRentalPeriod());
        int dateDifference = countDaysInPeriod(employee->carsRented[i]->getRentalPeriod());

        if(dateComparator(begginingOfRental, startDate) < 1 && dateComparator(endOfRental, endDate) > -1)
        {
            earnings += (employee->carsRented[i]->incomeFromRental / dateDifference) * findDateDifference(begginingOfRental, endOfRental) ;
            wage += employee->carsRented[i]->getEmployeeWage();
        }
        else if(dateComparator(endOfRental, endDate) > -1)
        {
            earnings += (employee->carsRented[i]->incomeFromRental / dateDifference) * findDateDifference(startDate, endOfRental);
            wage += employee->carsRented[i]->getEmployeeWage();
        }
        else if(dateComparator(begginingOfRental, startDate) < 1)
        {
            earnings += (employee->carsRented[i]->incomeFromRental / dateDifference) * findDateDifference(begginingOfRental ,endDate);
            wage += employee->carsRented[i]->getEmployeeWage();
        }
    }
    cout<<"The employee:\n"<<*employee<<"rentals brought the company "<<earnings<<" of earnings and costed the company "<<wage<<endl<<endl;
    return {earnings, wage};
}

int CarRentalCompany::getMileageOfCarForPeriod(Cars* car, string startDate, string endDate)
{
    int mileage = 0;
    for(int i=0 ; i<car->numberOfRentals ; i++)
    {
        string begginingOfRental = getFirstDate(car->rentalHistory[i]->getRentalPeriod());
        string endOfRental = getSecondDate(car->rentalHistory[i]->getRentalPeriod());
        int dateDifference = countDaysInPeriod(car->rentalHistory[i]->getRentalPeriod());

        if(dateComparator(begginingOfRental, startDate) < 1 && dateComparator(endOfRental, endDate) > -1)
        {
            mileage += car->rentalHistory[i]->distanceCovered;
        }
        else if(dateComparator(endOfRental, endDate) > -1)
        {
            mileage += car->rentalHistory[i]->distanceCovered;
        }
        else if(dateComparator(begginingOfRental, startDate) < 1)
        {
            mileage += car->rentalHistory[i]->distanceCovered;
        }
    }
    return mileage;
}

void CarRentalCompany::getFinancialStatisticsForPeriod(string startDate, string endDate)
{
    Currency earnings, costs;
    int rentals = 0;
    for(int i=0 ; i<carFleetSize ; i++)
    {
        pair<Currency, Currency> result = getFinancialStatisticsOfCarForPeriod(fleet[i], startDate, endDate);
        earnings += result.first;
        costs += result.second;
    }

    for(int i=0 ; i<numberOfClients ; i++)
    {
        pair<Currency, int> result = getFinancialStatisticsOfClientForPeriod(clients[i], startDate, endDate);
        rentals += result.second;
    }

    for(int i=0 ; i<numberOfEmployees ; i++)
    {
        pair<Currency, Currency> result = getFinancialStatisticsOfEmployeeForPeriod(employees[i], startDate, endDate);
        costs += result.second;
    }

    cout<<"During this period the company earned "<<earnings<<" making "<<rentals<<" rentals, and the expenses were "<<costs<<", so the company balance during this period is "<<earnings-costs<<endl<<endl;
}