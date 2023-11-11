#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(const int val);
        Fixed(const float val);

        ~Fixed();

        float toFloat(void) const;
        int toInt(void) const;

        Fixed & operator=(const Fixed &f);
        bool operator>(const Fixed &f);
        bool operator<(const Fixed &f);
        bool operator>=(const Fixed &f);
        bool operator<=(const Fixed &f);
        bool operator==(const Fixed &f);
        bool operator!=(const Fixed &f);
        friend Fixed operator+(const Fixed &f1, const Fixed &f2);
        friend Fixed operator-(const Fixed &f1, const Fixed &f2);
        friend Fixed operator*(const Fixed &f1, const Fixed &f2);
        friend Fixed operator/(const Fixed &f1, const Fixed &f2);
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        friend std::ostream& operator<<(std::ostream &stream, const Fixed &f);

        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);

    private:
        int _fVal;
        static const int _fractionalBits = 8;

} ;

#endif