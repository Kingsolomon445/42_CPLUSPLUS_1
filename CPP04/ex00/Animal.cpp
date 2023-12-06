#include "Animal.hpp"

//CONSTRUCTOR AND DESTRUCTOR
Animal::Animal(): type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal & other): type(other.type)
{
    std::cout << "Animal copy constructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
Animal & Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called!" << std::endl;
    static_cast<void>(other);
    return *this;
}

//MEMBER FUNCTION
void Animal::makeSound() const
{
    std::cout << "...................." << std::endl;
}

//GETTER
std::string Animal::getType() const
{
    return type;
}