#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & other)
{
    static_cast<void>(other);
}

Intern::~Intern() {}

Intern & Intern::operator=(const Intern & other)
{
    static_cast<void>(other);
    return *this;
}

const char* Intern::FormNotExist::what() const throw()
{
    return "Form doesn't exist!";
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}
AForm *Intern::makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    AForm * (Intern::*selectForm[3]) (std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return (this->*selectForm[i])(formTarget);
        }
    }
    throw FormNotExist();
    return 0;
}