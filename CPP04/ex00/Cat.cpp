#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat & other): Animal(other)
{
    std::cout << "Cat copy constructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
Cat & Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called!" << std::endl;
    static_cast<void>(other);
    return *this;
}


void Cat::makeSound() const
{
    std::cout << "MEOW MEOW MEOW MEOW MEOW!!!" << std::endl;
}