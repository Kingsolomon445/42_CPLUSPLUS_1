#ifndef DOG_H
# define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public AAnimal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(const Dog & other);
        ~Dog();

        Dog & operator=(const Dog &other);

        void makeSound() const ;
        Brain *getBrain() const;
        std::string getType() const;
} ;

#endif