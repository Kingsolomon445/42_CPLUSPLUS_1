#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap cozKar("cozkar");
    ClapTrap deGen("degen");

    cozKar.attack(deGen.getName());
    deGen.takeDamage(cozKar.getAttackD());
    deGen.beRepaired(1);

    return (0);
}