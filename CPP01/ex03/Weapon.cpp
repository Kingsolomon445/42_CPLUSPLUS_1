#include "Weapon.hpp"

Weapon::Weapon(): _type("") {}

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType()
{
    return _type;
}

void Weapon::setType(std::string type)
{
    _type = type;
}