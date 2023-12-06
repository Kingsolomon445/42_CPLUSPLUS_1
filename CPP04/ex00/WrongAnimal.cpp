#include "WrongAnimal.hpp"

//CONSTRUCTORS AND DESTRUCTORS
WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other): type(other.type)
{
    std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called!" << std::endl;
    static_cast<void>(other);
    return *this;
}


//MEMBER FUNCTIONS
void WrongAnimal::makeSound() const
{
     std::cout << "(WRONG ANIMAL) ................." << std::endl;
}

//GETTER
std::string WrongAnimal::getType() const
{
    return type;
}