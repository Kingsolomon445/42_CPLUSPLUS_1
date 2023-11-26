#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource();
        ~MateriaSource();

        void learnMateria(AMateria* materia);
        void AMateria* createMateria(std::string const &type);
} ;

#endif