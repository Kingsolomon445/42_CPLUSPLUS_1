#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
    private:
        std::string _name;
        int _materiaCount;
        AMateria *_materia;

    public:
        Character();
        Character(std::string name);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
} ;

#endif