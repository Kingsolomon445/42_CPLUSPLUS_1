#include "Bureaucrat.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Bureaucrat::Bureaucrat(): _grade(150), _name("nameless") {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _grade(other._grade), _name(other._name) {}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

//EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}


//GETTERS
std::string Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}

//MEMBER FUNCTIONS
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}


std::ostream& operator<<(std::ostream &stream, const Bureaucrat &b)
{
    stream << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return stream;
}