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
        int _materiaWasteCount;
        AMateria *_materia[4];
        int _materiaWaste[4];

    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character & other);

        Character & operator=(const Character &other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        static bool findElem(int idx, int size, int array[4]);
} ;

#endif