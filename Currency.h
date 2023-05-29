#include <iostream>

#pragma once

class Currency 
{
    private:
        
        int dollars;
        int cents;
        int convertForCalc(std::string Money);

    public:
        Currency(std::string Money);
        Currency();
        ~Currency() = default;
        
        std::string sign = "";

        std::string getCurrency() const;
        void setCurrency(std::string Money);

        Currency operator=(std::string Money);

        Currency operator*(int mult);
        Currency operator/(int div);

        std::string operator+=(std::string Money);
        std::string operator-=(std::string Money);
        std::string operator*=(int mult);
        std::string operator/=(int div);

        std::string operator+=(Currency Money);
        std::string operator-=(Currency Money);

        Currency operator+(Currency Money);
        Currency operator-(Currency Money);

        bool operator==(Currency Money);
        bool operator!=(Currency Money);
};

std::ostream& operator<<(std::ostream& os, const Currency& c);