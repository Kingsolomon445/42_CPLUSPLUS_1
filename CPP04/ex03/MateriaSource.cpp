#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called!";
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called!";
}

void MateriaSource::learnMateria(AMateria* materia)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type == "ice")
        return new Ice();
    else if (type == "cure")
        return new Cure();
    else
        return nullptr;
}