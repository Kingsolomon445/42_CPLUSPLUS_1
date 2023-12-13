#include <iostream>
#include <iomanip>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0.05f, 0.0f);
    Point b(8.0f, 15.07f);
    Point c(23.5f, 12.9f);
    Point p(5.0f, 8.45f);

    if (bsp(a, b, c, p))
        std::cout << "Point p lies inside the triangle" << std::endl;
    else
        std::cout << "Point p does not lie inside the triangle" << std::endl;

    return (0);
}


