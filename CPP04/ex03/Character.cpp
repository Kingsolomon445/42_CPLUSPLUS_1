#include "Character.hpp"

Character::Character(): _name("nameless"), _materiaCount(0)
{
    std::cout << "Character default constrcutor called!";
}

Character::Character(std::string name): _name(name), _materiaCount(0)
{
    std::cout << "Character overloaded constrcutor called!";
}

Character::~Character()
{
    std::cout << "Character destructor called!";
}

std::string const& Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (_materiaCount < 4)
    {
        _materia[0] = *m;
        _materiaCount++;
    }
}

void Character::unequip(int idx)
{
    
} 

void Character::use(int idx, ICharacter& target)
{

}