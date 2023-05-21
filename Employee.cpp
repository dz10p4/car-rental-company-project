#include <Employee.h>
#include <iostream>

using namespace std;

Employee::Employee(string cname, string csurname, string csocialSecurityNumber)
{
    name = cname;
    surname = csurname;
    socialSecurityNumber = csocialSecurityNumber;
}

Employee::~Employee()
{
    delete this;
}

string Employee::getName()
{
    return name;
}
string Employee::getSurname()
{
    return surname;
}
string Employee::getSocialSecurityNumber()
{
    return socialSecurityNumber;
}