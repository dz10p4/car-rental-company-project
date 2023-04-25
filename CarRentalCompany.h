#include <iostream>
#include <Employees.h>
#include <Client.h>
#include <Cars.h>
#include <Service.h>


using namespace std;

class CarRentalCompany 
{
    class RentalData 
    {
        Cars* rentedCar;

        Client* carUser;

        Employees* rentingEmployee;

        bool servicedAfterRental;

        Service** listOfServices;

        int costOfServices;

        int incomeFromRental;

        int distanceCovered;

        string rentalPeriod;

        string status;

    };




};