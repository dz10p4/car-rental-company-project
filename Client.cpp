#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(string cname, string csurname, string csocialSecurityNumber, string cdateOfRegistration)
{
    name = cname;
    surname = csurname;
    socialSecurityNumber = csocialSecurityNumber;
    dateOfRegistration = cdateOfRegistration;
}

Client::~Client()
{
    delete this;
}

string Client::getName() const
{
    return name;
}
string Client::getSurname() const
{
    return surname;
}
string Client::getSocialSecutityNumber() const
{
    return socialSecurityNumber;
}
string Client::getDateOfRegistration() const
{
    return dateOfRegistration;
}

ostream& operator<<(ostream& os, const Client& c)
{
    return os<<c.getName()<<" "<<c.getSurname()<<" "<<c.getSocialSecutityNumber()<<endl;
}