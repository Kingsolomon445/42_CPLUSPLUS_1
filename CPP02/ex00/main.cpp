#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    Fixed d;
    d.setRawBits(67);
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    std::cout << d.getRawBits() << std::endl;
    return 0;
}
