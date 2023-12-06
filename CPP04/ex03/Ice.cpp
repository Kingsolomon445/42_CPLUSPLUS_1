#include "Ice.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Ice::Ice(): AMateria("ice")
{
    type = "ice";
}

Ice::~Ice() {}

Ice::Ice(const Ice & other): AMateria(other) {}

//COPY ASSIGNMENT OPERATOR
Ice & Ice::operator=(const Ice &other)
{
    static_cast<void>(other);
    return *this;
}


//MEMBER FUNCTIONS
AMateria* Ice::clone() const
{
    Ice *newIceMateria = new Ice();
    return newIceMateria;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}