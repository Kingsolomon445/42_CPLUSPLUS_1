#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;


//CONSTRUCTORS AND DESTRUCTORS
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fVal = 0;
}

Fixed::Fixed(Fixed &other): _fVal(other._fVal)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fVal = other._fVal;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


//GETTERS AND SETTERS
int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fVal;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fVal = raw;
}