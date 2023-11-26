#include "WrongAnimal.hpp"

//CONSTRUCTORS AND DESTRUCTORS
WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!" << std::endl;
}

//MEMBER FUNCTIONS
void WrongAnimal::makeSound() const
{
     std::cout << "(WRONG ANIMAL) GRRRRRRHHHAAAA!!!!!!!!" << std::endl;
}

//GETTER
std::string WrongAnimal::getType() const
{
    return type;
}