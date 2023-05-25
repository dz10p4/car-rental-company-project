#include <iostream>
#include <Employee.h>
#include <Client.h>
#include <Cars.h>
#include <Service.h>

class CarRentalCompany 
{
    private:
        string companyName;
        int carFleetSize = 0;
        int numberOfEmployees = 0;
        int numberOfClients = 0;
        float income = 0;
        float costs = 0;
        Cars** fleet;
        Client** clients;
        Employee** employees;
    
    public:
        CarRentalCompany(string companyName);
        ~CarRentalCompany();

        //Data aquiring methods
        string getCompanyName();
        int getCarFleetSize();
        int getNumberOfEmployees();
        int getNumberOfClients();
        float getIncome();
        float getCosts();
        Cars** getCarArray();
        Client** getClientArray();
        Employee** getEmployeeArray();

        //Cars class methods
        void addVehicle(string make, string model, string year, string numberPlate, float initialMileage, float pricePerDay);
        void retireVehicle(Cars* car);
        void rentVehicle(Cars* rentedCar, Employee* rentingEmployee, Client* rentingClient, string rentalDate);
        void returnVehicle(Cars* car, string returnDate, float addedMileage);
        Cars* findByPlates(string numberPlates);
        
        //Service class methods
        void sendCarForService(Cars* car, string serviceType, string sendDate);
        void returnCarFromService(Cars* car, float cost, string returnDate);
        Service** getServiceHistoryOfCar(Cars* car);

        //Client class methods
        void registerClient(string name, string surname, string socialSecurityNumber, string dateOfRegistration);
        void removeClient(Client* client);
        Client* findClientBySocialSecurityNumber(string socialSecurityNumber);

        //Employee class methods
        void hireEmployee(string name, string surname, string socialSecurityNumber, float wage);
        void fireEmployee(Employee* employee);
        void changeWage(Employee* employee, float newWage);
        Employee* findEmployeeBySocialSecurityNumber(string socialSecurityNumber);

        //RentalData class methods
        RentalData** getRentalHistoryOfClient(Client* client);
        RentalData** getRentalHistoryOfCar(Cars* car);
        RentalData** getRentalHistoryOfEmployee(Employee* employee);
        void getFinancialStatisticsForPeriod(string startDate, string endDate);
        pair<int, int> getFinancialStatisticsOfCarForPeriod(Cars* car, string startDate, string endDate);
        pair<int, int> getFinancialStatisticsOfClientForPeriod(Client* client, string startDate, string endDate);
        pair<int, int> getFinancialStatisticsOfEmployeeForPeriod(Employee* employee, string startDate, string endDate);
        int getMileageOfCarForPeriod(Cars* car, string startDate, string endDate);
};