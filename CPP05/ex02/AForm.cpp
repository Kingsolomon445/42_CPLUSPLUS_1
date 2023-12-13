#include "AForm.hpp"

//CONSTRUCTORS AND DESTRUCTORS
AForm::AForm(): _isSigned(false), _requiredGradeToSign(100), _requiredGradeToExecute(50) {}

AForm::AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute): _name(name),
_isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
    if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
        throw GradeTooHighException();
    else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name), _isSigned(other._isSigned),
_requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute) {}

AForm::~AForm() {}

//OPERATOR OVERLOADING
AForm &AForm::operator=(const AForm & other)
{
    if (this != & other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &stream, const AForm &b)
{
    stream << "Form Name: " <<  b.getName() << "\n" << "Required Grade to Sign: "
    << b.getRequiredGradeToSign() << "\n" << "Required Grade to Execute: " << 
    b.getRequiredGradeToExecute() << "\n" << "Form is signed? " << b.isSigned() << "\n" << std::endl;
    return stream;
}

//EXCEPTION CLASSES
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}
const char* AForm::FormNotSigned::what() const throw()
{
    return "Form not Signed!";
}

//GETTERS
std::string AForm::getName() const
{
    return _name;
}

int AForm::getRequiredGradeToSign() const
{
    return _requiredGradeToSign;
}

int AForm::getRequiredGradeToExecute() const
{
    return _requiredGradeToExecute;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

//SETTER
void AForm::setIsSigned(bool isSigned)
{
    _isSigned = isSigned;
}

//MEMBER FUNCTIONS
void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _requiredGradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

