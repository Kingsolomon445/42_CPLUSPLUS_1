#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *_weapon;
        std::string _name;
    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();

        void setWeapon(Weapon weapon);
        void attack(void);
};

#endif