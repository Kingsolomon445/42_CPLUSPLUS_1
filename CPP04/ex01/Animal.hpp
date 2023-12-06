#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal & other);

        Animal & operator=(const Animal &other);

        virtual void makeSound() const;

        std::string getType() const;
} ;

#endif