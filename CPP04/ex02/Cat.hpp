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

        Cat & operator=(const Cat &other);


        void makeSound() const;
        Brain *getBrain() const;
        std::string getType() const;
} ;

#endif