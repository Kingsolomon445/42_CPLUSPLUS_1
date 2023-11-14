#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap & other);
        ~FragTrap();

        FragTrap & operator=(const FragTrap &other);

        void highFivesGuys(void);
} ;

#endif