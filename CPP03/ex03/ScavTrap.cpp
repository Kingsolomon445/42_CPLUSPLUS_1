#include "ScavTrap.hpp"

//CONSTRCUTORS AND DESTRUCTORS
ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << "ScavTrap default constructor has been called" << std::endl;
    _type = "ScavTrap";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    std::cout << "ScavTrap overloaded constructor has been created" << std::endl;
    _type = "ScavTrap";
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
    _type = other._type;
    return *this;
}


//MEMBER FUNCTION
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate mode." << std::endl;
}
