#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap cozKar("cozkar");
    DiamondTrap deGen("degen");

    cozKar.attack(deGen.getName());
    deGen.takeDamage(cozKar.getAttackD());
    deGen.beRepaired(1);
    deGen.highFivesGuys();
    deGen.guardGate();
    cozKar.whoAmI();
    
    return (0);
}

