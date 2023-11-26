#include "Animal.hpp"

//CONSTRUCTOR AND DESTRUCTOR
Animal::Animal(): type("Animal") {
    // std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    // std::cout << "Animal destructor called" << std::endl;
}

//MEMBER FUNCTION
void Animal::makeSound() const
{
    std::cout << "......................." << std::endl;
}

//GETTER
std::string Animal::getType() const
{
    return type;
}