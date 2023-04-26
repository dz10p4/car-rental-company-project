#include <iostream>
#include <CarRentalCompany.h>
using namespace std;

int main()
{

    CarRentalCompany* cmp = new CarRentalCompany("Brzebrzyk");

    if(cmp->getCompanyName() != "Brzebrzyk")
        cerr<<"wrong cmp name\n";
    
    cmp->addVehicle("Toyota", "Corolla", "2010", "WY 323AD", 467);
    cmp->addVehicle("Honda", "Jazz", "2009", "GA 3563A", 3253.34);
    cmp->addVehicle("Peugeot", "308", "2003", "WX 35AWD", 32453.23);

    if(cmp->getCarFleetSize() != 3)
        cerr<<"wrong fleet size\n";

    if(cmp->getCarArray()[2]->getMake() != "Peugeot")
        cerr<<"wrong make, should be 'Peugeot' and is "<<cmp->getCarArray()[2]->getMake()<<endl;

    if(cmp->getCarArray()[1]->mileage != 3253.34)
        cerr<<"wrong mileage for the second car\n";

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
        cerr<<"Error in finding employee by ss number\n";

    if(cmp->getNumberOfEmployees() != 3)
        cerr<<"Incorrect number of employees\n";

    cmp->registerClient("Jesse", "Pinkman", "52515125213", "23.01.2023");
    cmp->registerClient("Kim", "Wexler", "21525152", "25.01.2023");
    cmp->registerClient("Mike", "Ehrmantraut", "21512452", "25.01.2023");

    cmp->changeWage(cmp->findEmployeeBySocialSecurityNumber("21512452"),215412);
    if(cmp->getEmployeeArray()[2]->wage != 215421)
        cerr<<"error in changing wage";

    



}