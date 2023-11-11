#include "Fixed.hpp"

Fixed::Fixed()
{
    _fVal = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &f): _fVal(f._fVal)
{
    std::cout << "Copy constructor called" << std::endl;
}

void Fixed::operator=(const Fixed &f)
{
    _fVal = f._fVal;
    std::cout << "Copy assignment operator called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fVal;
}

void Fixed::setRawBits(int const raw)
{
    _fVal = raw;
    std::cout << "setRawBits member function called" << std::endl;
}