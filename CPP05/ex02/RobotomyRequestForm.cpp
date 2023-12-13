#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy Request Form", 72, 45)
{
    _target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
AForm("Robotomy Request Form", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other):
AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{
    *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    if (this != & other)
    {
        setIsSigned(other.isSigned());
        _target = other._target;
    }
    return *this;
}  


//MEMBER FUNCTIONS
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw FormNotSigned();
    else
    {
        if (executor.getGrade() <= getRequiredGradeToExecute())
        {
            std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
        }
        else
            throw GradeTooLowException();
    }
}