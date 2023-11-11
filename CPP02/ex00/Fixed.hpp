#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(Fixed &f);
        void operator=(const Fixed &f);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _fVal;
        static const int _fractionalBits = 8;
} ;

#endif