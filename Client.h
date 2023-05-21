#include <iostream>
#include <RentalData.h>

using namespace std;

class Client 
{
    private:
        string name;
        string surname;
        string socialSecurityNumber;
        string dateOfRegistration;
    
    public:
        Client(string name, string surname, string socialSecurityNumber, string dateOfRegistration);
        ~Client();
        bool isActive = true;
        int numberOfRentals = 0;
        int numberOfCurrentlyRentedCars = 0;
        float moneySpent = 0;
        RentalData** rentalHistory;

        string getName();
        string getSurname();
        string getSocialSecutityNumber();
        string getDateOfRegistration();
};