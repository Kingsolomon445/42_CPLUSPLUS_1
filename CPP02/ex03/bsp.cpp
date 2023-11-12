#include "Point.hpp"
#include "Fixed.hpp"

float f_abs(float n)
{
    if (n < 0)
        return n * -1;
    return n;
}

float area(float aX, float aY, float bX, float bY, float cX, float cY)
{
    return (
            f_abs
                (
                    roundf((
                        (aX * (bY - cY)) + 
                        (bX * (cY - aY)) + 
                        (cX * (aY - bY))
                    )  / 2.0)
                )
    );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float areaABC =  area(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
    float areaPAB = area(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat());
    float areaPAC = area(a.getX().toFloat(), a.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
    float areaPBC = area(point.getX().toFloat(), point.getY().toFloat(), b.getX().toFloat(),b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());

    return ((areaPAB + areaPAC + areaPBC) == areaABC);
}