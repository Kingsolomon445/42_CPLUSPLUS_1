#include "FragTrap.hpp"

//CONSTRCUTORS AND DESTRUCTORS
FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap default constructor has been called!" << std::endl;
    _name = "nameless";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap overloaded constructor has been called!" << std::endl;
    _name = name;
}

FragTrap::FragTrap(const FragTrap & other): ClapTrap(other._name)
{
    std::cout << "FragTrap copy constructor has been called!" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap has been destroyed" << std::endl;
}


//COPY ASSIGNMENT OPERATOR
FragTrap & FragTrap::operator=(const FragTrap &other)
{
    _hitP = other._hitP;
    _energyP = other._energyP;
    _attackD = other._attackD;
    _name = other._name;
    return *this;
}


//MEMBER FUNCTION
void FragTrap::attack(const std::string & target)
{
    if (_hitP <= 0)
        std::cout << "FragTrap " << _name << "is dead already!" << std::endl;
    else if (_energyP <= 0)
        std::cout << "FragTrap " << _name << "has no energy points to attack!" << std::endl;
    else
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackD << " points of damage!" << std::endl;
        _energyP--;
        showStats();
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " high-five 🖐️🖐️🖐️🖐️🖐️ all warriors" << std::endl;
}