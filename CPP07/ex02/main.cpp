#include <iostream>
#include "Array.hpp"

class Point
{
    public:
        Point() {};
        ~Point() {}

        int x;
        int y;
};

std::ostream& operator<<(std::ostream &stream, const Point &b)
{
    stream << "point x: " << b.x << std::endl;
    stream << "point y: " << b.y << std::endl;
    return stream;
}

int main(void)
{
    int size = 5;
    Array<int> intArr(size);
    Array<Point> pArr(size);

    for (int i = 0; i < 5; i++)
    {
        intArr[i] = i * 100 / 15;
        pArr[i].x = i * 100 / 15;
        pArr[i].y = -1 * (i * 100 / 15);
    }

    Array<int> intArrCopy(intArr);
    Array<Point> pArrCopy(size);
    pArrCopy = pArr;

    {
        std::cout << "Before modifying copy arrays.." << std::endl;
        std::cout << "Printing real int array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << intArr[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Printing copy int array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << intArrCopy[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Printing real point array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << pArr[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Printing copy point array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << pArrCopy[i] << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    {
        for (int i = 0; i < 5; i++)
        {
            intArrCopy[i] = i * 200 / 50;
            pArrCopy[i].x = i * 200 / 50;
            pArrCopy[i].y = -1 * (i * 200 / 50);
        }
        std::cout << "After modifying copy oarrays..." << std::endl;
        std::cout << "Printing real int array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << intArr[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Printing copy int array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << intArrCopy[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Printing real point array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << pArr[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Printing copy point array.." << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << pArrCopy[i] << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "Accessing elements with []" << std::endl;
        std::cout << "int array index 3: " << intArr[3] << std::endl;
        std::cout << "Point array index 3: " << pArr[3] << std::endl;

        try
        {
            std::cout << intArr[-2] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << pArr[10] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
   return 0;
}