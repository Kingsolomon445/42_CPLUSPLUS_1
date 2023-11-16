#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal
{
    public:
        Dog();
        ~Dog();

        void makeSound() const ;
} ;

#endif