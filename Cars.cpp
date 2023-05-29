#include "Cars.h"

using namespace std;

Cars::Cars(string cmake, string cmodel, string cyear, string cnumberPlate)
{   
    make = cmake;
    model = cmodel;
    year = cyear;
    numberPlate = cnumberPlate;
}

Cars::~Cars()
{
    delete this;
}

void Cars::setPricePerDay(Currency price)
{
    pricePerDay = price;
}

string Cars::getMake() const
{
    return make;
}
string Cars::getModel() const
{
    return model;
}
string Cars::getYear() const
{
    return year;
}
string Cars::getNumberPlate() const
{
    return numberPlate;
}

Currency Cars::getPricePerDay() const
{
    return pricePerDay;
}

ostream& operator<<(ostream& os, const Cars& c)
{
    return os<<c.getMake()<<" "<<c.getModel()<<" "<<c.getYear()<<" "<<"'"<<c.getNumberPlate()<<"'"<<endl;
}