#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
        virtual ~AAnimal() {};

        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
} ;

#endif