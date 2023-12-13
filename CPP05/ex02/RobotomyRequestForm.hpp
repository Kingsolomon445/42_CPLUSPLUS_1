#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
        
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &ppf);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(const RobotomyRequestForm &ppf);

        void execute(Bureaucrat const & executor) const;
} ;

#endif