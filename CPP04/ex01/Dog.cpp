#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog & other)
{
    std::cout << "Dog copy constructor called!" << std::endl;
    type = other.type;
    _brain = new Brain(*other._brain);
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "WOOF WOOF!" << std::endl;
}

Brain *Dog::getBrain()
{
    return _brain;
}