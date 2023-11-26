#include "Dog.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Dog::Dog()
{
    // std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog & other)
{
    // std::cout << "Dog copy constructor called!" << std::endl;
    type = other.type;
    _brain = new Brain(*other._brain);
}

Dog::~Dog()
{
    delete _brain;
    // std::cout << "Dog destructor called" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
Dog & Dog::operator=(const Dog &other)
{
    // std::cout << "Dog copy assignment called!" << std::endl;
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

//MEMBER FUNCTION
void Dog::makeSound() const
{
    std::cout << "WOOF WOOF!" << std::endl;
}

//GETTER
Brain *Dog::getBrain() const
{
    return _brain;
}

std::string Dog::getType() const
{
    return type;
}