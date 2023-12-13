#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        AForm *makePresidentialPardonForm(std::string target);
        AForm *makeShrubberyCreationForm(std::string target);
        AForm *makeRobotomyRequestForm(std::string target);
        
    public:
        Intern();
        ~Intern();
        Intern(const Intern & other);

        Intern & operator=(const Intern & other);

        AForm *makeForm(std::string formName, std::string formTarget);

        class FormNotExist: public std::exception
        {
            public:
                virtual const char* what() const throw();
        } ;

} ;


#endif