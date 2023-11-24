#include "ScavTrap.hpp"

//CONSTRCUTORS AND DESTRUCTORS
ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << "ScavTrap default constructor has been called" << std::endl;
    _name = "nameless";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    std::cout << "ScavTrap overloaded constructor has been created" << std::endl;
    _name = name;
}

ScavTrap::ScavTrap(const ScavTrap & other)
{
    std::cout << "ScavTrap copy constructor has been created" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap has been destroyed" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
ScavTrap & ScavTrap::operator=(const ScavTrap &other)
{
    _hitP = other._hitP;
    _energyP = other._energyP;
    _attackD = other._attackD;
    _name = other._name;
    return *this;
}

//MEMBER FUNCTION
void ScavTrap::attack(const std::string & target)
{
    if (_hitP <= 0)
        std::cout << "ScavTrap " << _name << "is dead already!" << std::endl;
    else if (_energyP <= 0)
        std::cout << "ScavTrap " << _name << "has no energy points to attack!" << std::endl;
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackD << " points of damage!" << std::endl;
        _energyP--;
        showStats();
    }
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now in Gate mode." << std::endl;
}
