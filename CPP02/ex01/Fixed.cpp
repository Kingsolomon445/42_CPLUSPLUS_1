#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

//CONSTRCUTORS AND DESTRUCTORS
Fixed::Fixed(): _fVal(0)
{
    std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): _fVal(other._fVal)
{
    std::cout << "Copy contructor called" << std::endl;
}

Fixed::Fixed(const int val): _fVal(val * (1 << _fractionalBits))
{
    std::cout << "Int contructor called" << std::endl;
}

Fixed::Fixed(const float val): _fVal(roundf(val * (1 << _fractionalBits)))
{
    std::cout << "Float contructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


//OPERATORS OVERLOADING
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fVal = other.getRawBits();
    return *this;
}

std::ostream& operator <<(std::ostream &stream, const Fixed &f)
{
    stream << f.toFloat();
    return stream;
}



//CONVERSION MEMBER FUNCTIONS
int Fixed::toInt() const
{
    return _fVal >> _fractionalBits;
}

float Fixed::toFloat() const
{
    return (float)_fVal / (float)(1 << _fractionalBits);
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
