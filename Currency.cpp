#include "Currency.h"
#include <iostream>

using namespace std;

Currency::Currency()
{
    setCurrency("0");
}

Currency::Currency(std::string Money)
{
    setCurrency(Money);
}

std::string Currency::getCurrency() const
{
    if(cents!=0)
    {
        return sign+to_string(dollars)+'.'+to_string(cents);
    }
    else return sign+to_string(dollars);
}

void Currency::setCurrency(std::string Money)
{
    dollars = 0;
    cents = 0;
    int i=0;

    if(Money[i] == '-')
    {
        sign = "-";
        i++;
    }
    for(; i<Money.size() ; i++)
    {
        if(Money[i]=='.')break;
        dollars += Money[i]-'0';
        dollars *= 10;
    }
    dollars/=10;
    i++;
    if(Money.size() > i)
    {
        cents += Money[i] - '0';
        cents *= 10;
        i++;
    }
    if(Money.size() > i)
    {
        cents += Money[i] - '0';
    }
}

int Currency::convertForCalc(std::string Money)
{
    int cdollars = 0;
    int ccents = 0;
    int i=0;
    int csign = 1;

    if(Money[i] == '-')
    {
        csign = -1;
        i++;
    }

    for( ; i<Money.size() ; i++)
    {
        if(Money[i]=='.')break;
        cdollars += Money[i]-'0';
        cdollars *= 10;
    }

    cdollars/=10;
    i++;
    if(Money.size() > i)
    {
        ccents += Money[i] - '0';
        ccents *= 10;
        i++;
    }
    if(Money.size() > i)
    {
        ccents += Money[i] - '0';
    }

    return csign*cdollars * 100 + ccents;
}

Currency Currency::operator=(std::string Money)
{
    Currency a(Money);
    setCurrency(Money);
    return a;
}


Currency Currency::operator*(int mult)
{
    int result = (dollars * 100 + cents) * mult;
    return Currency(to_string(result/100)+'.'+to_string(result%100));
}

Currency Currency::operator/(int div)
{
    int result = (dollars * 100 + cents) / div;
    
    return Currency(to_string(result/100)+'.'+to_string(result%100));
}

std::string Currency::operator+=(std::string Money)
{
    int result = convertForCalc(Money) + dollars * 100 + cents;

    dollars = result / 100;
    cents = result % 100;
    return to_string(dollars)+'.'+to_string(cents);
}

std::string Currency::operator-=(std::string Money)
{
    int result = dollars * 100 + cents - convertForCalc(Money);

    dollars = result / 100;
    cents = result % 100;

    return to_string(dollars)+'.'+to_string(cents);
}

std::string Currency::operator*=(int mult)
{
    int result = (dollars * 100 + cents) * mult;

    dollars = result / 100;
    cents = result % 100;

    return to_string(dollars)+'.'+to_string(cents);
}

std::string Currency::operator/=(int div)
{
    int result = (dollars * 100 + cents) / div;

    dollars = result / 100;
    cents = result % 100;

    return to_string(dollars)+'.'+to_string(cents);
}

std::string Currency::operator+=(Currency Money)
{
    int result = convertForCalc(getCurrency()) + convertForCalc(Money.getCurrency());
    dollars = result/100;
    cents = result%100;

    return to_string(dollars)+'.'+to_string(cents);
}

std::string Currency::operator-=(Currency Money)
{
    int result = convertForCalc(getCurrency()) - convertForCalc(Money.getCurrency());
    dollars = result/100;
    cents = result%100;

    return to_string(dollars)+'.'+to_string(cents);
}

Currency Currency::operator+(Currency Money)
{
    int result = convertForCalc(getCurrency()) + convertForCalc(Money.getCurrency());

    return Currency(to_string(result/100)+'.'+to_string(result%100));
}

Currency Currency::operator-(Currency Money)
{
    int result = convertForCalc(getCurrency()) - convertForCalc(Money.getCurrency());
    string csign = "";
    if(result<0) csign = "-";
    result = abs(result);

    return Currency(csign+to_string(result/100)+'.'+to_string(result%100));
}

bool Currency::operator==(Currency Money)
{
    return getCurrency() == Money.getCurrency();
}

bool Currency::operator!=(Currency Money)
{
    return getCurrency() != Money.getCurrency();
}

ostream& operator<<(ostream& os, const Currency& c)
{
    return os<<c.getCurrency();
}