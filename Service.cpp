#include <Service.h>
#include <iostream>

using namespace std;

Service::Service(string cserviceType)
{
    serviceType = cserviceType;
}

Service::~Service()
{
    delete this;
}

string Service::getServiceType()
{
    return serviceType;
}
float Service::getPrice()
{
    return price;
}
string Service::getServicePeriod()
{
    return servicePeriod;
}
int Service::getLengthOfService()
{
    return lengthOfService;
}

void Service::modifyLengthOfService(int newLength)
{
    lengthOfService = newLength; 
}

void Service::appendServicePeriod(string returnDate)
{
    servicePeriod += " - " + returnDate;
}