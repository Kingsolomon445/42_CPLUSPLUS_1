#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called!" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other): WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
WrongCat & WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator called!" << std::endl;
    static_cast<void>(other);
    return *this;
}

void WrongCat::makeSound() const
{
     std::cout << "(WRONG CAT) MEOW MEOW MEOW!!!!!!!!" << std::endl;
}