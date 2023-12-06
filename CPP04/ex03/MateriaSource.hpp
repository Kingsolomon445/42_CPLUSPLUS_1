#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *_learnedMateria[4];
        int _learnedMateriaCount;

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource & other);

        MateriaSource & operator=(const MateriaSource &other);

        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const &type);
} ;

#endif