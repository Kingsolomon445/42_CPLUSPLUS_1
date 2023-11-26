#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Cure consrcutor called!" << std::endl;
    type = "cure";
}

Cure::~Cure()
{
    std::cout << "Cure destructor called!" << std::endl;
}

Cure & Cure::operator=(const Cure &other)
{
    static_cast<void>(other);
    return *this;
}

AMateria* Cure::clone() const
{
    Cure *newIceMateria = new Cure();
    //Work on this
    return newIceMateria;
}

void Cure::use(ICharacter& target)
{

}