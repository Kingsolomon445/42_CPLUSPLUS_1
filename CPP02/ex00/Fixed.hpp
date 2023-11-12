#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fVal;
        static const int _fractionalBits;
} ;

#endif