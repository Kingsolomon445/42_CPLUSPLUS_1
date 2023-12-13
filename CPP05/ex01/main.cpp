#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void)
{
    Bureaucrat b1(40, "Lord");
    Bureaucrat b2(100, "king");
    Form f1;
    Form f2("Presidential Form", 80, 10);

    std::cout << b1;
    std::cout << b2;
    std::cout << std::endl;
    std::cout << f1;
    std::cout << f2;

    try 
    {
        f1.beSigned(b1);
        b2.signForm(f2);

        std::cout << std::endl;
        std::cout << f1;
        std::cout << f2;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
