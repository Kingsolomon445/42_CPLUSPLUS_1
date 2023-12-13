#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("Presidential Pardon Form", 25, 5)
{
    _target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
AForm("Presidential Pardon Form", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other):
AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{
    *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    if (this != & other)
    {
        setIsSigned(other.isSigned());
        _target = other._target;
    }
    return *this;
}  


//MEMBER FUNCTIONS
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw FormNotSigned();
    else
    {
        if (executor.getGrade() <= getRequiredGradeToExecute())
            std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        else
            throw GradeTooLowException();
    }
}