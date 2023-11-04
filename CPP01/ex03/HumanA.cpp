#include "HumanA.hpp"

HumanA::HumanA(): _name("default name"), _weapon(Weapon()) {}

HumanA::HumanA(std::string name, Weapon weapon): _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}