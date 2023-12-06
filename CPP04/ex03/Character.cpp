#include "Character.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Character::Character(): _name("nameless"), _materiaCount(0), _materiaWasteCount(0) {}

Character::Character(std::string name): _name(name), _materiaCount(0), _materiaWasteCount(0) {}

Character::~Character()
{
    for (int i = 0; i < _materiaCount; i++)
    {
        delete _materia[i];
    }
}

Character::Character(const Character & other)
{
    _name = other._name;
    _materiaCount = other._materiaCount;
    _materiaWasteCount = other._materiaWasteCount;
    for (int i = 0; i < _materiaWasteCount; i++)
    {
        _materiaWaste[i] = other._materiaWaste[i];
    }
    for (int i = 0; i < _materiaCount; i++)
    {
        _materia[i] = other._materia[i]->clone();
    }
}

//COPY ASSIGNMENT OPERATOR
Character & Character::operator=(const Character &other)
{
    if (this != & other)
    {
        for (int i = 0; i < _materiaCount; i++)
            delete _materia[i];
        _name = other._name;
        _materiaCount = other._materiaCount;
        _materiaWasteCount = other._materiaWasteCount;
        for (int i = 0; i < _materiaWasteCount; i++)
            _materiaWaste[i] = other._materiaWaste[i];
        for (int i = 0; i < _materiaCount; i++)
            _materia[i] = other._materia[i]->clone();
    }
    return *this;
}

//GETTER
std::string const& Character::getName() const
{
    return _name;
}

//MEMBER FUNCTIONS
void Character::equip(AMateria* m)
{
    if (_materiaCount < 4)
    {
        _materia[_materiaCount] = m;
        _materiaCount++;
    }
    else
        delete m;
}

bool Character::findElem(int idx, int size, int array[4])
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == idx)
            return true;
    }
    return false;
}

void Character::unequip(int idx)
{
    if (findElem(idx, _materiaWasteCount, _materiaWaste) || idx > 3 || idx < 0)
        return;
    _materiaWaste[_materiaWasteCount] = idx;
    _materiaCount--;
    _materiaWasteCount++;
} 

void Character::use(int idx, ICharacter& target)
{
    if (findElem(idx, _materiaWasteCount, _materiaWaste) || idx > 3 || idx < 0)
        return;
    _materia[idx]->use(target);
}