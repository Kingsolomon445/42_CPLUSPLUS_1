#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &ppf);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=(const ShrubberyCreationForm &ppf);

        void execute(Bureaucrat const & executor) const;
} ;

#endif