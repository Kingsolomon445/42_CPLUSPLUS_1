#include "MateriaSource.hpp"

//CONSTRUCTORS AND DESTRUCTORS
MateriaSource::MateriaSource(): _learnedMateriaCount(0) {}


MateriaSource::~MateriaSource()
{
    for (int i = 0; i < _learnedMateriaCount; i++)
    {
        delete _learnedMateria[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource & other)
{
    _learnedMateriaCount = other._learnedMateriaCount;
    for (int i = 0; i < _learnedMateriaCount; i++)
    {
        _learnedMateria[i] = other._learnedMateria[i]->clone();
    }
}

//COPY ASSIGNMENT OPERATOR
MateriaSource & MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < _learnedMateriaCount; i++)
        {
            delete _learnedMateria[i];
        }
        _learnedMateriaCount = other._learnedMateriaCount;
        for (int i = 0; i < _learnedMateriaCount; i++)
        {
            _learnedMateria[i] = other._learnedMateria[i]->clone();
        }
    }
    return *this;
}

//MEMBER FUNCTIONS
void MateriaSource::learnMateria(AMateria* materia)
{
    if (_learnedMateriaCount < 4)
    {
        _learnedMateria[_learnedMateriaCount] = materia;
        _learnedMateriaCount++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _learnedMateriaCount; i++)
    {
        if (_learnedMateria[i]->getType() == type)
            return _learnedMateria[i]->clone();
    }
    return 0;
}
