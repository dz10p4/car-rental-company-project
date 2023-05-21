#include <Cars.h>

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

string Cars::getMake()
{
    return make;
}
string Cars::getModel()
{
    return model;
}
string Cars::getYear()
{
    return year;
}
string Cars::getNumberPlate()
{
    return numberPlate;
}