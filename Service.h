#include <iostream>
using namespace std;

class Service
{
    private:
        string serviceType;
        float price;
        string servicePeriod;
        int lengthOfService;
    public:
        Service();
        ~Service();

        string getServiceType();
        float getPrice();
        string getServicePeriod();
        int getLengthOfService();
};