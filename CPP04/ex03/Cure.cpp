#include "Cure.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Cure::Cure(): AMateria("cure")
{
    type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure & other): AMateria(other) {}

//COPY ASSIGNMENT OPERATOR
Cure & Cure::operator=(const Cure &other)
{
    static_cast<void>(other);
    return *this;
}

//MEMBER FUNCTIONS
AMateria* Cure::clone() const
{
    Cure *newIceMateria = new Cure();
    return newIceMateria;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}