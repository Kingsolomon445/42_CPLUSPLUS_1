#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _requiredGradeToSign;
        const int _requiredGradeToExecute;

    public:
        Form();
        Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
        Form(const Form &f);
        ~Form();
        Form & operator=(const Form &f);

        std::string getName() const;
        bool isSigned() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExecute() const;
        void beSigned(const Bureaucrat &b);

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        } ;

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        } ;

} ;

std::ostream& operator<<(std::ostream &stream, const Form &b);

#endif