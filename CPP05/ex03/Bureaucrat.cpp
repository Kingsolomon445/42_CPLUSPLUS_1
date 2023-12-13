#include "Bureaucrat.hpp"

//CONSTRUCTORS AND DESTRUCTORS
Bureaucrat::Bureaucrat(): _grade(150), _name("nameless") {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _grade(other._grade), _name(other._name) {}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooHighException();
    else
        _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

//OPERATOR OVERLOADING
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != & other)
        _grade = other._grade;
    return *this;
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &b)
{
    stream << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return stream;
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

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << "Bureaucrat, " << _name <<  " signed Form, " << f.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Bureaucrat, " << _name <<  " couldn't sign Form, " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & f)
{
    try
    {
        f.execute(*this);
        std::cout << "Bureaucrat, " << _name << " executed Form, " << f.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Bureaucrat, " << _name <<  " couldn't execute Form, " << f.getName() << " because " << e.what() << std::endl;
    }
}

