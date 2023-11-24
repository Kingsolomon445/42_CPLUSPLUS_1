#include "ClapTrap.hpp"

//CONSTRCUTORS AND DESTRUCTORS
ClapTrap::ClapTrap(): _hitP(100), _energyP(50), _attackD(30), _name("nameless")
{
    std::cout << "ClapTrap default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _hitP(100), _energyP(50), _attackD(30), _name(name)
{
    std::cout << "ClapTrap Overloaded constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & other)
{
    std::cout << "ClapTrap Copy constructor has been called" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap has been destroyed" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
ClapTrap & ClapTrap::operator=(const ClapTrap &other)
{
    _hitP = other._hitP;
    _energyP = other._energyP;
    _attackD = other._attackD;
    _name = other._name;
    return *this;
}

//MEMBER FUNCTIONS
void ClapTrap::attack(const std::string & target)
{
    if (_hitP <= 0)
        std::cout << "ClapTrap " << _name << "is dead already!" << std::endl;
    else if (_energyP <= 0)
        std::cout << "ClapTrap " << _name << "has no energy points to attack!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackD << " points of damage!" << std::endl;
        _energyP--;
        showStats();
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitP <= 0)
        std::cout << "ClapTrap " << _name << "has no hit points to attack!" << std::endl;
    else if ((int)amount > _hitP)
    {
        _hitP = 0;
        std::cout << "ClapTrap " << _name << "just got smacked down!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " has taken damage by " << amount << "!." << std::endl;
        _hitP -= amount;
        showStats();
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitP <= 0)
        std::cout << "ClapTrap " << " " << _name << "is dead already!" << std::endl;
    else if (_energyP <= 0)
        std::cout << "ClapTrap " << " " << _name << "has no energy points to be repair itself!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << " " << _name << " has repaired its health by " << amount << "!." << std::endl;
        _hitP += amount;
        _energyP--;
        showStats();
    }
}

void ClapTrap::showStats()
{
    std::cout << "ClapTrap " << " " << _name << " has " <<  _hitP << " hit points and " << _energyP << " energy points left!" << std::endl;
}



//GETTERS AND SETTERS
std::string ClapTrap::getName()
{
    return _name;
}

int ClapTrap::getEnergyP()
{
    return _energyP;
}

int ClapTrap::getHitP()
{
    return _hitP;
}

int ClapTrap::getAttackD()
{
    return _attackD;
}

void ClapTrap::setName(std::string name)
{
    _name = name;
}


