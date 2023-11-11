#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default contructor called" << std::endl;
    _fVal = 0;
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy contructor called" << std::endl;
    _fVal = f._fVal;
}

Fixed::Fixed(const int val)
{
    std::cout << "Int contructor called" << std::endl;
    _fVal = val * (1 << _fractionalBits);
}

Fixed::Fixed(const float val)
{
    std::cout << "Float contructor called" << std::endl;
    _fVal = roundf(val * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fVal = f._fVal;
}

std::ostream& operator <<(std::ostream &stream, const Fixed &f)
{
    stream << f.toFloat();
    return stream;
}


int Fixed::toInt() const
{
    return _fVal >> _fractionalBits;
}

float Fixed::toFloat() const
{
    return (float)_fVal / (float)(1 << _fractionalBits);
}
