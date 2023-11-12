#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c = Fixed(189.562700f);

    std::cout << "a  = " <<  a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "--c = " << --c << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "c-- = " << c-- << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "max(a, b) = " <<  Fixed::max( a, b ) << std::endl;
    std::cout << "min(a, b) = " <<  Fixed::min( a, b ) << std::endl;

    std::cout << "a + b = " << (a  + b) << std::endl;
    std::cout << "b - a = " << (b  - a) << std::endl;
    std::cout << "a * b = " << (a  * b) << std::endl;
    std::cout << "b / a = " << (b  / a) << std::endl;

    std::cout << "a > b = " << (a > b) << std::endl;
    std::cout << "b < c = " << (b < c) << std::endl;
    std::cout << "a >= b = " << (a >= b) << std::endl;
    std::cout << "c <= a = " << (c  <= a) << std::endl;
    std::cout << "a == a = " << (a  == a) << std::endl;
    std::cout << "b != c = " << (b  != c) << std::endl;

    return 0;
}
