#include "DiamondTrap.hpp"

//CONSTRUCTORS AND DESTRUCTORS
DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor has been called!" << std::endl;
    _type = "DiamondTrap";
    _name = "nameless";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + std::string("_clap_name")), ScavTrap(name + std::string("_clap_name")), FragTrap(name + std::string("_clap_name"))
{
    std::cout << "DiamondTrap overloaded constructor has been called!" << std::endl;
    _type = "DiamondTrap";
    _name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap & other)
{
    std::cout << "DiamondTrap copy constructor has been called!" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap has been destroyed" << std::endl;
}


//COPY ASSIGNMENT OPERATOR
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &other)
{
    _hitP = other._hitP;
    _energyP = other._energyP;
    _attackD = other._attackD;
    _name = other._name;
    _type = other._type;
    return *this;
}


//MEMBER FUNCTION

void DiamondTrap::showStats() const
{
    std::cout << _type << " " << _name << " has " <<  _hitP << " hit points and " << _energyP << " energy points left!" << std::endl;
}
void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is: " << _name << std::endl;
    std::cout << "My Claptrap name is: " << ClapTrap::_name << std::endl;
}