#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog & other): Animal(other)
{
    std::cout << "Dog copy constructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
Dog & Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called!" << std::endl;
    static_cast<void>(other);
    return *this;
}


void Dog::makeSound() const
{
    std::cout << "WOOF WOOF!" << std::endl;
}