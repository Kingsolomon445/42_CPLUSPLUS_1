#include "AMateria.hpp"

// AMateria::AMateria(std::string const & type)
// {
//     this->type = type;
//     std::cout << "AMateria constructor called!" << std::endl;
// }

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called!" << std::endl;
}

AMateria & AMateria::operator=(const AMateria &other)
{
    static_cast<void>(other);
    return *this;
}

std::string const& AMateria::getType() const
{
    return type;
}