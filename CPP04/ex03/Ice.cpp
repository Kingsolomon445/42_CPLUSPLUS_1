#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "Ice consrcutor called!" << std::endl;
    type = "ice";
}

Ice::~Ice()
{
    std::cout << "Ice destructor called!" << std::endl;
}

Ice & Ice::operator=(const Ice &other)
{
    static_cast<void>(other);
    return *this;
}


AMateria* Ice::clone() const
{
    Ice *newIceMateria = new Ice();
    //Work on this
    return newIceMateria;
}

void Ice::use(ICharacter& target)
{

}