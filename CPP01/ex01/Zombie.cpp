#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {std::cout << "I am destroyed!" << std::endl;}

void Zombie::setName(std::string name)
{
    _name = name;
}
void Zombie::announce()
{
    std::cout << "I am " << _name << "! I am a zombie." << std::endl;
}