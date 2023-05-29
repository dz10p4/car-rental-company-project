#include <iostream>
#include "CarRentalCompany.h"
using namespace std;

int main()
{
    int errors = 0;
    // Creating a company class
    CarRentalCompany* cmp = new CarRentalCompany("Brzebrzyk");

    if(cmp->getCompanyName() != "Brzebrzyk")
    {
        cerr<<"wrong cmp name\n";
        errors++;
    }

    //Adding vehicles
    cmp->addVehicle("Toyota", "Corolla", "2010", "WY 323AD", 467, "25.5");
    cmp->addVehicle("Honda", "Jazz", "2009", "GA 3563A", 3253, "30.78");
    cmp->addVehicle("Peugeot", "307", "2003", "WX 35AWD", 32453, "10.25");
    cmp->addVehicle("Lada", "Niva", "1995", "GD AS2DA", 400000, "5.5");
    cmp->addVehicle("Honda", "Jazz", "2010", "WOT 24ADG", 80000, "35.57");
    cmp->addVehicle("Polonez", "Caro", "2000", "WY FSW2D", 523623, "5");
    cmp->addVehicle("Mazda", "MX-5", "2005", "W2 DZIUNIA", 25000, "40");

    //Testing info of added vehicles
    if(cmp->getCarFleetSize() != 7)
    {
        cerr<<"wrong fleet size, should be 7 and is "<<cmp->getCarFleetSize()<<endl;
        errors++;
    }

    if(cmp->getCarArray()[2]->getMake() != "Peugeot")
    {
        cerr<<"wrong make, should be 'Peugeot' and is "<<cmp->getCarArray()[2]->getMake()<<endl;
        errors++;
    }

    if(cmp->getCarArray()[1]->getModel() != "Jazz")
    {
        cerr<<"wrong model, should be 'Jazz' and is "<<cmp->getCarArray()[1]->getModel()<<endl;
        errors++;
    }

    if(cmp->getCarArray()[0]->getNumberPlate() != "WY 323AD")
    {
        cerr<<"wrong number plate, should be 'WY 323AD' and is "<<cmp->getCarArray()[0]->getNumberPlate()<<endl;
        errors++;
    }

    if(cmp->getCarArray()[3]->getYear() != "1995")
    {
        cerr<<"wrong year, should be '1995' and is "<<cmp->getCarArray()[2]->getYear()<<endl;
        errors++;
    }

    if(cmp->getCarArray()[1]->mileage != 3253)
    {
        cerr<<"wrong mileage for the second car, should be '3253' and is "<<cmp->getCarArray()[1]->mileage<<endl;
        errors++;
    }

    if(cmp->findByPlates("GA 3563A") != cmp->getCarArray()[1])
    {
        cerr<<"error in find by plates function\n";
        errors++;
    }
    
    //Testing the retireVehicle function
    cmp->retireVehicle(cmp->findByPlates("GA 3563A"));

    if(cmp->findByPlates("GA 3563A")->readyForRental)
    {
        cerr<<"error in car retiring\n";
        errors++;
    }

    //Testing service functions
    cmp->sendCarForService(cmp->findByPlates("GA 3563A"),"Error returning","18.01.2023");
    cout<<"The above message 'You cannot send this car to service.' is expected."<<endl;
    //The above call should return an error

    cmp->sendCarForService(cmp->findByPlates("WX 35AWD"),"Cleaning","18.01.2023");

    if(cmp->findByPlates("WX 35AWD")->readyForRental)
    {
        cerr<<"error in ready for rental variable\n";
        errors++;
    }

    if(cmp->findByPlates("WX 35AWD")->serviceHistory[cmp->findByPlates("WX 35AWD")->numberOfServices]->getServiceType() != "Cleaning")
    {
        cerr<<"error in type of service";
        errors++;
    }

    //Hiring employees and testing info
    cmp->hireEmployee("Jack", "Sparrow", "213769420", "20.3");
    cmp->hireEmployee("Mick", "Jagger", "61121423", "35.2");
    cmp->hireEmployee("Walter", "White", "236135235", "22.55");
    cmp->hireEmployee("Saul", "Goodman", "278653492", "27.55");

    if(cmp->findEmployeeBySocialSecurityNumber("61121423")->getName() != "Mick")
    {
        cerr<<"error in finding employee by ss number\n";
        errors++;
    }

    if(cmp->getNumberOfEmployees() != 4)
    {
        cerr<<"incorrect number of employees\n";
        errors++;
    }
    //Registering clients and testing info
    cmp->registerClient("Gus", "Fring", "263246562", "20.01.2023");
    cmp->registerClient("Jesse", "Pinkman", "52515125213", "23.01.2023");
    cmp->registerClient("Kim", "Wexler", "21525152", "25.01.2023");
    cmp->registerClient("Mike", "Ehrmantraut", "2151345452", "25.01.2023");

    if(cmp->findClientBySocialSecurityNumber("21525152")->getSurname() != "Wexler")
    {
        cerr<<"error in finding client by ss number\n";
        errors++;
    }
    //Testing changing wage
    cmp->changeWage(cmp->findEmployeeBySocialSecurityNumber("236135235"), "25.6");
    if(cmp->getEmployeeArray()[2]->wage != Currency("25.6"))
    {
        cerr<<"error in changing wage\n";
        errors++;
    }

    //Renting some cars
    cmp->rentVehicle(cmp->findByPlates("WY 323AD"), cmp->findEmployeeBySocialSecurityNumber("236135235"), cmp->findClientBySocialSecurityNumber("2151345452"), "25.04.2023");
    cmp->rentVehicle(cmp->findByPlates("GD AS2DA"), cmp->findEmployeeBySocialSecurityNumber("278653492"), cmp->findClientBySocialSecurityNumber("21525152"), "25.04.2023");
    cmp->rentVehicle(cmp->findByPlates("W2 DZIUNIA"), cmp->findEmployeeBySocialSecurityNumber("236135235"), cmp->findClientBySocialSecurityNumber("2151345452"), "25.04.2023");
    cmp->rentVehicle(cmp->findByPlates("WY FSW2D"), cmp->findEmployeeBySocialSecurityNumber("61121423"), cmp->findClientBySocialSecurityNumber("52515125213"), "25.04.2023");

    if(cmp->findByPlates("W2 DZIUNIA")->isRented == false)
    {
        cerr<<"error in isRented variable\n";
        errors++;
    }

    Client* mike = cmp->findClientBySocialSecurityNumber("2151345452");

    if(mike->numberOfCurrentlyRentedCars != 2)
    {
        cerr<<"error in numberOfCurrentlyRentedCars variable\n";
        errors++;
    }

    if(mike->rentalHistory[0]->getRentedCar()->getMake() != "Toyota")
    {
        cerr<<"error in the rented car data\n";
        errors++;
    }
    
    //Returning car from service
    cmp->returnCarFromService(cmp->findByPlates("WX 35AWD"), "50.78", "20.01.2023");

    if(cmp->findByPlates("WX 35AWD")->readyForRental == false)
    {
        cerr<<"error in readyForRental variable after returning car from service\n";
        errors++;
    }

    if(cmp->getServiceHistoryOfCar(cmp->findByPlates("WX 35AWD"))[0]->getServiceType() != "Cleaning" || cmp->getServiceHistoryOfCar(cmp->findByPlates("WX 35AWD"))[0]->getLengthOfService() != 2)
    {
        cerr<<"error in servicehistory registry\n";
        errors++;
    }
    //Return cars from clients
    cmp->returnVehicle(cmp->findByPlates("WY 323AD"), "30.04.2023", 30);
    cmp->returnVehicle(cmp->findByPlates("GD AS2DA"), "30.04.2023", 50);
    cmp->returnVehicle(cmp->findByPlates("W2 DZIUNIA"), "30.04.2023", 45);
    cmp->returnVehicle(cmp->findByPlates("WY FSW2D"), "30.04.2023", 20);

    if(cmp->findByPlates("WY 323AD")->isRented != false)
    {
        cerr<<"error in isRented variable\n";
        errors++;
    }

    if(cmp->findByPlates("WY 323AD")->mileage != 467+30)
    {
        cerr<<"error in mileage calculations\n";
        errors++;
    }

    if(cmp->findByPlates("WY 323AD")->rentalHistory[0]->getCarUser()->getName() != "Mike")
    {
        cerr<<"error in rentalHistory data\n";
        errors++;
    }

    //Let's ban a client
    cmp->removeClient(cmp->findClientBySocialSecurityNumber("52515125213"));

    if(cmp->findClientBySocialSecurityNumber("52515125213")->isActive != false)
    {
        cerr<<"error in client removal\n";
        errors++;
    }

    //And now it's time to fire somebody
    cmp->fireEmployee(cmp->findEmployeeBySocialSecurityNumber("61121423"));

    if(cmp->findEmployeeBySocialSecurityNumber("61121423")->isEmployed != false)
    {
        cerr<<"error in firing the employee\n";
        errors++;
    }
    //Let's try to make transactions with banned users
    cmp->rentVehicle(cmp->findByPlates("WY FSW2D"), cmp->findEmployeeBySocialSecurityNumber("61121423"), cmp->findClientBySocialSecurityNumber("21525152"), "2.05.2023");
    cout<<"Above message about employee not being able to rent vehicle is expected"<<endl;
    
    cmp->rentVehicle(cmp->findByPlates("WY FSW2D"), cmp->findEmployeeBySocialSecurityNumber("278653492"), cmp->findClientBySocialSecurityNumber("52515125213"), "2.05.2023");
    cout<<"Above message about client not being able to rent vehicle is expected"<<endl<<endl;

    //Borrowing and servicing some vehicles to boost the statistics for the further checking of statistics functions.
    cmp->rentVehicle(cmp->findByPlates("W2 DZIUNIA"), cmp->findEmployeeBySocialSecurityNumber("278653492"), cmp->findClientBySocialSecurityNumber("21525152"), "3.05.2023");
    cmp->rentVehicle(cmp->findByPlates("WY FSW2D"), cmp->findEmployeeBySocialSecurityNumber("236135235"), cmp->findClientBySocialSecurityNumber("21525152"), "5.05.2023");

    cmp->returnVehicle(cmp->findByPlates("W2 DZIUNIA"), "11.05.2023", 40);
    cmp->returnVehicle(cmp->findByPlates("WY FSW2D"), "14.05.2023", 35);

    cmp->sendCarForService(cmp->findByPlates("W2 DZIUNIA"), "Vacuuming", "13.04.2023");
    cmp->returnCarFromService(cmp->findByPlates("W2 DZIUNIA"), "10.23", "15.04.2023");

    pair<Currency, Currency> result1 = cmp->getFinancialStatisticsOfCarForPeriod(cmp->findByPlates("W2 DZIUNIA"), "25.04.2023", "15.05.2023");
    if(result1.first != Currency("520"))
    {
        cerr<<"Error in calculations of car earnings"<<endl;
        errors++;
    }

    if(result1.second != Currency("10.23"))
    {
        cerr<<"Error in calculations of car costs"<<endl;
        errors++;
    }

    result1 = cmp->getFinancialStatisticsOfEmployeeForPeriod(cmp->findEmployeeBySocialSecurityNumber("236135235"), "25.02.2023", "15.05.2023");
    if(result1.first != Currency("372.5"))
    {
        cerr<<"Error in calculations of employee rental earnings"<<endl;
        errors++;
    }

    if(result1.second != Currency("76.8"))
    {
        cerr<<"Error in calculations of employee salary"<<endl;
        errors++;
    }

    pair<Currency, int> result2 = cmp->getFinancialStatisticsOfClientForPeriod(cmp->findClientBySocialSecurityNumber("21525152"), "25.02.2023", "15.05.2023");
    if(result2.first != Currency("392.5"))
    {
        cerr<<"Error in calculations of income from client"<<endl;
        errors++;
    }
    
    if(result2.second != 3)
    {
        cerr<<"Error in calculations of number of rentals from client"<<endl;
        errors++;
    }
    //Last but not least let's run the void finiancial function
    cout<<endl;
    cmp->getFinancialStatisticsForPeriod("25.02.2023", "15.05.2023");

    cout<<endl<<"End of tests, "<<errors<<" bug(s) reported."<<endl;
    return 0;
}