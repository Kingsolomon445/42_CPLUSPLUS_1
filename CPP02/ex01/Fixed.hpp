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

        void operator=(const Fixed &f);
        friend std::ostream& operator<<(std::ostream &stream, const Fixed &f);

    private:
        int _fVal;
        static const int _fractionalBits = 8;

} ;

#endif