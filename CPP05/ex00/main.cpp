#include <iostream>
#include "Bureaucrat.hpp"


int main(void)
{
    Bureaucrat b1;
    Bureaucrat b2(100, "king");
    Bureaucrat b3(140, "President");
    Bureaucrat b4(1, "Governor");

    std::cout << b1;
    std::cout << b2;

    try 
    {
        b1.incrementGrade();
        std::cout << b1 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    for (int i = 0; i < 5; i++)
    {
        b1.incrementGrade();
        b2.decrementGrade();
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    return (0);
}
