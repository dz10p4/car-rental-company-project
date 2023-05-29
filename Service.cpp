#include <iostream>
#include "Service.h"

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
Currency Service::getPrice()
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

void Service::modifyServicePeriod(string startDate)
{
    servicePeriod = startDate;
}

void Service::appendServicePeriod(string returnDate)
{
    servicePeriod += " - " + returnDate;
}

void Service::updatePrice(Currency cprice)
{
    price = cprice;
}