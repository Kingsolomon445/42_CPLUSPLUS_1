#include "Form.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Form::Form(): _name("General Form"), _isSigned(false), _requiredGradeToSign(100), _requiredGradeToExecute(50) {}

Form::Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute): _name(name),
_isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
    if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
        throw GradeTooHighException();
    else if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned),
_requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExecute(other._requiredGradeToExecute) {}

Form::~Form() {}

//OPERATOR OVERLOADING
Form &Form::operator=(const Form & other)
{
    if (this != & other)
        _isSigned = other._isSigned;
    return *this;
}

std::ostream& operator<<(std::ostream &stream, const Form &b)
{
    stream << "Form Name: " <<  b.getName() << "\n" << "Required Grade to Sign: "
    << b.getRequiredGradeToSign() << "\n" << "Required Grade to Execute: " << 
    b.getRequiredGradeToExecute() << "\n" << "Form is signed? " << b.isSigned() << "\n" << std::endl;
    return stream;
}

//EXCEPTION CLASSES
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

//GETTERS
std::string Form::getName() const
{
    return _name;
}

int Form::getRequiredGradeToSign() const
{
    return _requiredGradeToSign;
}

int Form::getRequiredGradeToExecute() const
{
    return _requiredGradeToExecute;
}

bool Form::isSigned() const
{
    return _isSigned;
}

//MEMBER FUNCTIONS
void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= _requiredGradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

