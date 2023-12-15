#include "Data.hpp"

Data::Data() {}

Data::Data(int x, int y): _x(x), _y(y) {}

Data::Data(const Data & other): _x(other._x), _y(other._y) {}

Data::~Data() {}

Data & Data::operator=(const Data & other)
{
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

int Data::getX() const
{
    return _x;
}

int Data::getY() const
{
    return _y;
}