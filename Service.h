#include <iostream>

class Service
{
    private:
        string serviceType;
        float price;
        string servicePeriod;
        int lengthOfService;
    public:
        Service(string serviceType);
        ~Service();

        string getServiceType();
        float getPrice();
        string getServicePeriod();
        int getLengthOfService();

        void modifyLengthOfService(int newLength);
        void appendServicePeriod(string returnDate);
};