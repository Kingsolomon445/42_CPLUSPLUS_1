#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        std::string getType();
        void setType(std::string type);
};
#endif