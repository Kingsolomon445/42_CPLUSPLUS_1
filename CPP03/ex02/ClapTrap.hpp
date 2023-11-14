#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    protected:
        int _hitP;
        int _energyP;
        int _attackD;
        std::string _name;
        std::string _type;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap();

        ClapTrap & operator=(const ClapTrap &other);


        void attack(const std::string & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStats();

        std::string getName();
        int getEnergyP();
        int getHitP();
        int getAttackD();

        void setName(std::string name);

} ;
#endif