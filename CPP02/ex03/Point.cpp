#include "Point.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &other): _x(other._x), _y(other._y) {}

Point::~Point() {}

//ASSIGNMENT OPERATOR OVERLOADING
Point &Point::operator=(const Point &other)
{
    static_cast<void>(other);
    return *this;
}


//GETTERS
Fixed Point::getX() const
{
    return _x;
}
Fixed Point::getY() const
{
    return _y;
}