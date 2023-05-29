#include <iostream>
#include <vector>

#pragma once
#include "Employee.h"
#include "Client.h"
#include "Cars.h"
#include "Service.h"
#include "Currency.h"
#pragma endregion

class Currency;

class CarRentalCompany 
{
    private:
        std::string companyName;
        int carFleetSize = 0;
        int numberOfEmployees = 0;
        int numberOfClients = 0;
        std::vector<Cars*> fleet;
        std::vector<Client*> clients;
        std::vector<Employee*> employees;
    
    public:
        CarRentalCompany(std::string companyName);
        ~CarRentalCompany();

        //Data aquiring methods
        std::string getCompanyName();
        int getCarFleetSize();
        int getNumberOfEmployees();
        int getNumberOfClients();
        std::vector<Cars*> getCarArray();
        std::vector<Client*> getClientArray();
        std::vector<Employee*> getEmployeeArray();

        //Cars class methods
        void addVehicle(std::string make, std::string model, std::string year, std::string numberPlate, int initialMileage, std::string pricePerDay);
        void retireVehicle(Cars* car);
        void rentVehicle(Cars* rentedCar, Employee* rentingEmployee, Client* rentingClient, std::string rentalDate);
        void returnVehicle(Cars* car, std::string returnDate, int addedMileage);
        Cars* findByPlates(std::string numberPlates);
        bool checkIfThisCarIsInDatabase(std::string numberPlate);

        //Service class methods
        void sendCarForService(Cars* car, std::string serviceType, std::string sendDate);
        void returnCarFromService(Cars* car, std::string cost, std::string returnDate);
        std::vector<Service*> getServiceHistoryOfCar(Cars* car);

        //Client class methods
        void registerClient(std::string name, std::string surname, std::string socialSecurityNumber, std::string dateOfRegistration);
        void removeClient(Client* client);
        Client* findClientBySocialSecurityNumber(std::string socialSecurityNumber);
        bool checkIfThisClientIsInDatabase(std::string socialSecurityNumber);

        //Employee class methods
        void hireEmployee(std::string name, std::string surname, std::string socialSecurityNumber, std::string wage);
        void fireEmployee(Employee* employee);
        void changeWage(Employee* employee, std::string newWage);
        Employee* findEmployeeBySocialSecurityNumber(std::string socialSecurityNumber);
        bool checkIfThisEmployeeIsInDatabase(std::string socialSecurityNumber);

        //RentalData class methods
        std::vector<RentalData*> getRentalHistoryOfClient(Client* client);
        std::vector<RentalData*> getRentalHistoryOfCar(Cars* car);
        std::vector<RentalData*> getRentalHistoryOfEmployee(Employee* employee);
        std::pair<Currency, Currency> getFinancialStatisticsOfCarForPeriod(Cars* car, std::string startDate, std::string endDate);
        std::pair<Currency, int> getFinancialStatisticsOfClientForPeriod(Client* client, std::string startDate, std::string endDate);
        std::pair<Currency, Currency> getFinancialStatisticsOfEmployeeForPeriod(Employee* employee, std::string startDate, std::string endDate);
        int getMileageOfCarForPeriod(Cars* car, std::string startDate, std::string endDate);
        void getFinancialStatisticsForPeriod(std::string startDate, std::string endDate);

        //Calculations methods
        int findDateDifference(std::string datea1, std::string datea2);
        int stoif(std::string money);
        std::string getFirstDate(std::string date);
        std::string getSecondDate(std::string date);
        int dateComparator(std::string first, std::string second);
        int countDaysInPeriod(std::string period);
};