#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &ppf);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(const PresidentialPardonForm &ppf);

        void execute(Bureaucrat const & executor) const;
} ;

#endif