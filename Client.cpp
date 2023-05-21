#include <Client.h>
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

string Client::getName()
{
    return name;
}
string Client::getSurname()
{
    return surname;
}
string Client::getSocialSecutityNumber()
{
    return socialSecurityNumber;
}
string Client::getDateOfRegistration()
{
    return dateOfRegistration;
}