#include "Fixed.hpp"


//CONSTRCUTORS AND DESTRUCTORS
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



//COMPARISON OPERATORS OVERLOADING 
bool Fixed::operator>(const Fixed &f)
{
    return (_fVal > f._fVal);
}
bool Fixed::operator<(const Fixed &f)
{
    return (_fVal < f._fVal);
}
bool Fixed::operator>=(const Fixed &f)
{
    return (_fVal >= f._fVal);
}
bool Fixed::operator<=(const Fixed &f)
{
return (_fVal <= f._fVal);
}
bool Fixed::operator==(const Fixed &f)
{
   return (_fVal == f._fVal);
}
bool Fixed::operator!=(const Fixed &f)
{
    return (_fVal != f._fVal);
}



//ARITMETIC OPERATORS OVERLOADING
Fixed operator+(const Fixed &f1, const Fixed &f2)
{
    return f1.toFloat() + f2.toFloat();
}
Fixed operator-(const Fixed &f1, const Fixed &f2)
{
    return f1.toFloat() - f2.toFloat();
}
Fixed operator*(const Fixed &f1, const Fixed &f2)
{
   return Fixed(f1.toFloat() * f2.toFloat());
}
Fixed operator/(const Fixed &f1, const Fixed &f2)
{
   return Fixed(f1.toFloat() / f2.toFloat());
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
Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fVal = f._fVal;
    return (*this);
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


//MIN AND MAX MEMBER FUNCTIONS
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1._fVal < f2._fVal)
        return f1;
    return f2;
}
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1._fVal < f2._fVal)
        return f1;
    return f2;
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1._fVal > f2._fVal)
        return f1;
    return f2;
}
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1._fVal > f2._fVal)
        return f1;
    return f2;
}
