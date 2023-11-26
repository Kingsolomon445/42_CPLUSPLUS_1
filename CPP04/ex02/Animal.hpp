#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        virtual ~Animal() {};

        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
} ;

#endif