#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called!" << std::endl;
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

void Cat::makeSound() const
{
    std::cout << "MEOW MEOW MEOW MEOW MEOW!!!" << std::endl;
}

Brain *Cat::getBrain()
{
    return _brain;
}