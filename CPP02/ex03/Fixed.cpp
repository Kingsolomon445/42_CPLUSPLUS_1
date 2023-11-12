#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

//CONSTRCUTORS AND DESTRUCTORS
Fixed::Fixed(): _fVal(0) {}

Fixed::Fixed(const Fixed &other): _fVal(other._fVal) {}

Fixed::Fixed(const int val): _fVal(val * (1 << _fractionalBits)) {}

Fixed::Fixed(const float val): _fVal(roundf(val * (1 << _fractionalBits))) {}

Fixed::~Fixed() {}


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
    return _fVal;
}

void Fixed::setRawBits(int const raw)
{
    _fVal = raw;
}


//COMPARISON OPERATORS OVERLOADING
bool Fixed::operator>(const Fixed &other) const
{
    return (_fVal > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (_fVal < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (_fVal >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (_fVal <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
   return (_fVal == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (_fVal != other.getRawBits());
}



//ARITMETIC OPERATORS OVERLOADING
Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed  Fixed::operator-(const Fixed &other) const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
   return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)  const
{
   return Fixed(toFloat() / other.toFloat());
}


//INCREMENTS AND DECREMENTS OPERATORS OVERLOADING
Fixed &Fixed::operator++()
{
    ++_fVal;
    return *this;
}

Fixed &Fixed::operator--()
{
    --_fVal;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++_fVal;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --_fVal;
    return (tmp);
}


//OTHER OPERATORS OVERLOADING
Fixed &Fixed::operator=(const Fixed &other)
{
    _fVal = other.getRawBits();
    return (*this);
}

std::ostream& operator <<(std::ostream &stream, const Fixed &other)
{
    stream << other.toFloat();
    return stream;
}



//MIN AND MAX MEMBER FUNCTIONS
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    return f2;
}
