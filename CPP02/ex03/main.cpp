#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 30.0f);
    Point c(20.0f, 0.0f);
    Point p(10.0f, 15.0f);

    if (bsp(a, b, c, p))
        std::cout << "Point p lies inside the triangle" << std::endl;
    else
        std::cout << "Point p does not lie inside the triangle" << std::endl;

    return (0);
}
