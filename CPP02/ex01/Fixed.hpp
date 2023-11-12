#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int val);
        Fixed(const float val);
        ~Fixed();
        Fixed & operator=(const Fixed &other);

        float toFloat(void) const;
        int toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);


    private:
        int _fVal;
        static const int _fractionalBits;

} ;

std::ostream& operator<<(std::ostream &stream, const Fixed &f);

#endif