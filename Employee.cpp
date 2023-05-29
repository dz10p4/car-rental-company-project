#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(string cname, string csurname, string csocialSecurityNumber, Currency cwage)
{
    name = cname;
    surname = csurname;
    socialSecurityNumber = csocialSecurityNumber;
    wage = cwage;
}

Employee::~Employee()
{
    delete this;
}

string Employee::getName() const
{
    return name;
}
string Employee::getSurname() const
{
    return surname;
}
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

ostream& operator<<(ostream& os, const Employee& e)
{
    return os<<e.getName()<<" "<<e.getSurname()<<" "<<e.getSocialSecurityNumber()<<endl;
}