#include <iostream>
using namespace std;

class Service
{
    public:
        Service();
        ~Service();

        string serviceType;
        float price;
        string servicePeriod;
        int lengthOfService;
};