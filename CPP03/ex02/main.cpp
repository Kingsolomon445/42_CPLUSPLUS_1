#include "FragTrap.hpp"

int main(void)
{
    FragTrap cozKar("cozkar");
    FragTrap deGen("degen");

    cozKar.attack(deGen.getName());
    deGen.takeDamage(cozKar.getAttackD());
    deGen.beRepaired(1);
    deGen.highFivesGuys();
    
    return (0);
}