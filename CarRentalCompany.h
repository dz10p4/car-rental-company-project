#include <iostream>
#include <Employee.h>
#include <Client.h>
#include <Cars.h>
#include <Service.h>

using namespace std;

class CarRentalCompany 
{
    private:
        string companyName;
        int carFleetSize;
        int numberOfEmployees;
        int numberOfClients;
        float income;
        float costs;
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
        void addVehicle(string make, string model, string year, string numberPlate, float initialMileage); 
        void retireVehicle(Cars* car);
        void rentVehicle(Cars* rentedCar, Employee* rentingEmployee, Client* rentingClient);
        void returnVehicle(Cars* car, int serviceLength, float addedMileage);
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
        void getFinancialStatisticsOfCarForPeriod(Cars* car, string startDate, string endDate);
        void getFinancialStatisticsOfClientForPeriod(Client* client, string startDate, string endDate);
        void getFinancialStatisticsOfEmployeeForPeriod(Employee* employee, string startDate, string endDate);
        void getMileageOfCarForPeriod(Cars* car, string startDate, string endDate);
};