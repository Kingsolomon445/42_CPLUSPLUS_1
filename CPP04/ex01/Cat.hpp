#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(const Cat & other);
        ~Cat();


        void makeSound() const;
        Brain *getBrain();
} ;

#endif