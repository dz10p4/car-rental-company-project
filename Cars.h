#include <iostream>
#include <RentalData.h>
#include <Service.h>

using namespace std;

class Cars 
{
    private:
        string make;
        string model;
        string year;
        string numberPlate;
        
    public:
        Cars();
        ~Cars();
        bool readyForRental = true;
        bool isRented = false;

        float mileage;
        int numberOfDaysInService = 0;
        int numberOfRentals = 0;
        int numberOfServices = 0;
        float moneyMade = 0;

        RentalData** rentalHistory;
        Service** serviceHistory;

        string getMake();
        string getModel();
        string getYear();
        string getNumberPlate();
};