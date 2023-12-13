#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;


class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _requiredGradeToSign;
        const int _requiredGradeToExecute;

    public:
        AForm();
        AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
        AForm(const AForm &f);
        virtual ~AForm();
        AForm & operator=(const AForm &f);

        void setIsSigned(bool isSigned);

        std::string getName() const;
        bool isSigned() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExecute() const;
        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSigned: public std::exception
        {
            public:
                virtual const char* what() const throw();
        } ;
} ;

std::ostream& operator<<(std::ostream &stream, const AForm &b);

#endif