#include "DiamondTrap.hpp"

//CONSTRUCTORS AND DESTRUCTORS
DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor has been called!" << std::endl;
    _name = "nameless";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + std::string("_clap_name")), ScavTrap(name + std::string("_clap_name")), FragTrap(name + std::string("_clap_name"))
{
    std::cout << "DiamondTrap overloaded constructor has been called!" << std::endl;
    _name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap & other): ClapTrap(other._name + std::string("_clap_name")), ScavTrap(other._name + std::string("_clap_name")), FragTrap(other._name + std::string("_clap_name"))
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
    return *this;
}


//MEMBER FUNCTION

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is: " << _name << std::endl;
    std::cout << "My Claptrap name is: " << this->ClapTrap::_name << std::endl;
}