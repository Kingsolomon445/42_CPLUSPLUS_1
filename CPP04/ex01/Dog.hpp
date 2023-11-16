#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(const Dog & other);
        ~Dog();

        void makeSound() const ;
        Brain *getBrain();
} ;

#endif