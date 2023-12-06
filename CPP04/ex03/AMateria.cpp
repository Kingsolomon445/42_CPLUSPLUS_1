#include "AMateria.hpp"

//CONSTRUCTORS AND DESTRUCTORS
AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria & other): type(other.type) {}

//COPY ASSIGNMENT OPERATOR
AMateria & AMateria::operator=(const AMateria &other)
{
    static_cast<void>(other);
    return *this;
}

//GETTER
std::string const& AMateria::getType() const
{
    return type;
}

//MEMBER FUNCTION
void AMateria::use(ICharacter & target)
{
    static_cast<void>(target);
}