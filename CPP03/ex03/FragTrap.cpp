#include "FragTrap.hpp"

//CONSTRCUTORS AND DESTRUCTORS
FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap default constructor has been called!" << std::endl;
    _type = "FragTrap";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap overloaded constructor has been called!" << std::endl;
    _type = "FragTrap";
}

FragTrap::FragTrap(const FragTrap & other)
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
    _type = other._type;
    return *this;
}


//MEMBER FUNCTION
void FragTrap::highFivesGuys(void)
{
    std::cout << _type << " " << _name << " high-five 🖐️🖐️🖐️🖐️🖐️ all warriors" << std::endl;
}