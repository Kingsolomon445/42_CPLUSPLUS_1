#include "Cat.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Cat::Cat()
{
    std::cout << "Cat default constructor called!" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat & other)
{
    std::cout << "Cat copy constructor called!" << std::endl;
    type = other.type;
    _brain = new Brain(*other._brain);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
Cat & Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

//MEMBER FUNCTION
void Cat::makeSound() const
{
    std::cout << "MEOW MEOW MEOW MEOW MEOW!!!" << std::endl;
}

//GETTERS
Brain *Cat::getBrain() const
{
    return _brain;
}

std::string Cat::getType() const
{
    return type;
}