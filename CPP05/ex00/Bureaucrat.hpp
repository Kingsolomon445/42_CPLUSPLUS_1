#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>


class Bureaucrat
{
    private:
        int _grade;
        const std::string _name;

    public:
        Bureaucrat();
        Bureaucrat(int grade, std::string name);
        Bureaucrat(const Bureaucrat & b);
        ~Bureaucrat();

        Bureaucrat & operator=(const Bureaucrat &other);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

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

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &b);


#endif