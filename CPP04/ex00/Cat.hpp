#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include <iostream>

class Cat: public Animal
{
    public:
        Cat();
        ~Cat();

        void makeSound() const;
} ;

#endif