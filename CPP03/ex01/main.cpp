#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap cozKar("cozkar");
    ScavTrap deGen("degen");

    cozKar.attack(deGen.getName());
    deGen.takeDamage(cozKar.getAttackD());
    deGen.beRepaired(1);
    deGen.guardGate();
    
    return (0);
}