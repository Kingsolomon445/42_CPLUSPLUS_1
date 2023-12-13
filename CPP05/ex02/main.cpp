#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void)
{
    Bureaucrat b1(40, "Lord");
    Bureaucrat b2(146, "King");
    Bureaucrat b3(6, "President");

    PresidentialPardonForm ppf("Nikita");
    RobotomyRequestForm rrf("Dixon");
    ShrubberyCreationForm scf("seraf");

    std::cout << b1;
    std::cout << b2;
    std::cout << b3;
    std::cout << std::endl;
    std::cout << ppf;
    std::cout << rrf;
    std::cout << scf;

    try 
    {
        b3.signForm(ppf);
        b3.executeForm(ppf);
        std::cout << std::endl;
        rrf.beSigned(b1);
        rrf.execute(b1);
        std::cout << std::endl;
        b2.signForm(scf);
        b2.executeForm(scf);
        std::cout << std::endl;
        // std::cout << f1;
        // std::cout << f2;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
