#include "Point.hpp"
#include "Fixed.hpp"


Fixed area(Fixed aX, Fixed aY, Fixed bX, Fixed bY, Fixed cX, Fixed cY)
{
    return (
                (
                        (aX * (bY - cY)) + 
                        (bX * (cY - aY)) + 
                        (cX * (aY - bY))
                )  / 2
    );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC =  area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
    Fixed areaPAB = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
    Fixed areaPAC = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
    Fixed areaPBC = area(point.getX(), point.getY(), b.getX(),b.getY(), c.getX(), c.getY());

    return ((areaPAB + areaPAC + areaPBC) == areaABC);
}