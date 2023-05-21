#include <iostream>
#include <CarRentalCompany.h>
using namespace std;

int main()
{
    CarRentalCompany* cmp = new CarRentalCompany("Brzebrzyk");

    if(cmp->getCompanyName() != "Brzebrzyk")
        cerr<<"wrong cmp name\n";
    
    cmp->addVehicle("Toyota", "Corolla", "2010", "WY 323AD", 467, 20);
    cmp->addVehicle("Honda", "Jazz", "2009", "GA 3563A", 3253.34, 30);
    cmp->addVehicle("Peugeot", "307", "2003", "WX 35AWD", 32453.23, 10);

    if(cmp->getCarFleetSize() != 3)
        cerr<<"wrong fleet size, should be 3 and is "<<cmp->getCarFleetSize()<<endl;

    if(cmp->getCarArray()[2]->getMake() != "Peugeot")
        cerr<<"wrong make, should be 'Peugeot' and is "<<cmp->getCarArray()[2]->getMake()<<endl;

    if(cmp->getCarArray()[1]->getModel() != "Jazz")
        cerr<<"wrong model, should be 'Jazz' and is "<<cmp->getCarArray()[1]->getModel()<<endl;

    if(cmp->getCarArray()[0]->getNumberPlate() != "WY 323AD")
        cerr<<"wrong number plate, should be 'WY 323AD' and is "<<cmp->getCarArray()[0]->getNumberPlate()<<endl;

    if(cmp->getCarArray()[2]->getYear() != "2003")
        cerr<<"wrong year, should be '2003' and is "<<cmp->getCarArray()[2]->getYear()<<endl;

    if(cmp->getCarArray()[1]->mileage != 3253.34)
        cerr<<"wrong mileage for the second car, should be '3253.34' and is "<<cmp->getCarArray()[1]->mileage<<endl;;

    if(cmp->findByPlates("GA 3563A") != cmp->getCarArray()[1])
        cerr<<"error in find by plates function\n";

    cmp->retireVehicle(cmp->findByPlates("GA 3563A"));

    if(cmp->getCarFleetSize() != 2)
        cerr<<"error in car retiring\n";

    cmp->sendCarForService(cmp->findByPlates("WX 35AWD"),"Cleaning","18.01.2023");

    if(cmp->getCarFleetSize() != 1)
        cerr<<"wrong fleet size after sending to service\n";

    cmp->hireEmployee("Jack", "Sparrow", "213769420", 3400.34);
    cmp->hireEmployee("Mick", "Jagger", "61121423",5332.23);
    cmp->hireEmployee("Walter", "White", "135235", 15212.21);

    if(cmp->findEmployeeBySocialSecurityNumber("61121423")->getName() != "Mick")
        cerr<<"error in finding employee by ss number\n";

    if(cmp->getNumberOfEmployees() != 3)
        cerr<<"incorrect number of employees\n";

    cmp->registerClient("Jesse", "Pinkman", "52515125213", "23.01.2023");
    cmp->registerClient("Kim", "Wexler", "21525152", "25.01.2023");
    cmp->registerClient("Mike", "Ehrmantraut", "21512452", "25.01.2023");

    if(cmp->findClientBySocialSecurityNumber("21525152")->getSurname() != "Wexler")
        cerr<<"error in finding client by ss number\n";

    cmp->changeWage(cmp->findEmployeeBySocialSecurityNumber("135235"),21541);
    if(cmp->getEmployeeArray()[2]->wage != 21541)
        cerr<<"error in changing wage\n";

    cmp->rentVehicle(cmp->findByPlates("WY 323AD"), cmp->findEmployeeBySocialSecurityNumber("135235"), cmp->findClientBySocialSecurityNumber("21512452"), "25.04.2023");

    if(cmp->findByPlates("WY 323AD")->isRented == false)
        cerr<<"error in isRented variable\n";

    Client* mike = cmp->findClientBySocialSecurityNumber("21512452");

    if(mike->numberOfCurrentlyRentedCars != 1)
        cerr<<"error in numberOfCurrentlyRentedCars variable\n";

    if(mike->rentalHistory[0]->getRentedCar()->getMake() != "Toyota")
        cerr<<"error in the rented car data\n";

    cmp->returnCarFromService(cmp->findByPlates("WX 35AWD"), 200, "20.01.2023");

    if(cmp->findByPlates("WX 35AWD")->readyForRental == false)
        cerr<<"error in readyForRental variable after returning car from service\n";

    if(cmp->getServiceHistoryOfCar(cmp->findByPlates("WX 35AWD"))[0]->getServiceType() != "Cleaning" || cmp->getServiceHistoryOfCar(cmp->findByPlates("WX 35AWD"))[0]->getLengthOfService() != 2)
        cerr<<"error in servicehistory registry\n";

    cmp->returnVehicle(cmp->findByPlates("WY 323AD"), 5, 30.2);

    if(cmp->findByPlates("WY 323AD")->isRented != false)
        cerr<<"error in isRented variable\n";

    if(cmp->findByPlates("WY 323AD")->mileage == 467+30.2)
        cerr<<"error in mileage calculations\n";

    if(cmp->findByPlates("WY 323AD")->rentalHistory[0]->getCarUser()->getName() != "Mike")
        cerr<<"error in rentalHistory data\n";
    
    cmp->removeClient(cmp->findClientBySocialSecurityNumber("52515125213"));

    if(cmp->findClientBySocialSecurityNumber("52515125213")->isActive != false)
        cerr<<"error in client removal\n";

    cmp->fireEmployee(cmp->findEmployeeBySocialSecurityNumber("61121423"));

    if(cmp->findEmployeeBySocialSecurityNumber("61121423")->isEmployed != false)
        cerr<<"error in firing the employee\n";

}