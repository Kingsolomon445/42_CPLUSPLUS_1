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

void WrongCat::makeSound() const
{
     std::cout << "(WRONG CAT) MEOW MEOW MEOW!!!!!!!!" << std::endl;
}