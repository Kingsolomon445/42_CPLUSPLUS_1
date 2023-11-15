#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string _name;
        
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap & other);
        ~DiamondTrap();

        DiamondTrap & operator=(const DiamondTrap & other);

        void showStats() const;
        void whoAmI();
} ;

#endif