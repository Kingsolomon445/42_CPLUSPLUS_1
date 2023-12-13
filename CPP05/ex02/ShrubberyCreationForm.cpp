#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Shrubbery Creation Form", 145, 137)
{
    _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
AForm("Shrubbery Creation Form", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other):
AForm(other.getName(), other.getRequiredGradeToSign(), other.getRequiredGradeToExecute())
{
   *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    if (this != & other)
    {
        setIsSigned(other.isSigned());
        _target = other._target;
    }
    return *this;
}  


//MEMBER FUNCTIONS
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw FormNotSigned();
    else
    {
        if (executor.getGrade() <= getRequiredGradeToExecute())
        {
            std::string fileName = _target + std::string("_shrubbery");
            std::ofstream targetForm(fileName.c_str());
            targetForm << "                                    .";
            targetForm << "                                     .         ;  " << std::endl;
            targetForm << "        .              .              ;%     ;;   " << std::endl;
            targetForm << "          ,           ,                :;%  %;   " << std::endl;
            targetForm << "           :         ;                   :;%;'     .,   " << std::endl;
            targetForm << "  ,.        %;     %;            ;        %;'    ,;" << std::endl;
            targetForm << "    ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
            targetForm << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
            targetForm << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
            targetForm << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
            targetForm << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
            targetForm << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
            targetForm << "              `@%:.  :;%.         ;@@%;'   " << std::endl;
            targetForm << "                `@%.  `;@%.      ;@@%;      "   << std::endl;
            targetForm << "                  `@%%. `@%%    ;@@%;        " << std::endl;
            targetForm << "                    ;@%. :@%%  %@@%;       " << std::endl;
            targetForm << "                      %@bd%%%bd%%:;     " << std::endl;
            targetForm << "                        #@%%%%%:;;" << std::endl;
            targetForm << "                        %@@%%%::;" << std::endl;
            targetForm << "                        %@@@%(o);  . '      "   << std::endl;
            targetForm << "                        %@@@o%;:(.,'         " << std::endl;
            targetForm << "                    `.. %@@@o%::;         " << std::endl;
            targetForm << "                       `)@@@o%::;         " << std::endl;
            targetForm << "                        %@@(o)::;        " << std::endl;
            targetForm << "                       .%@@@@%::;         " << std::endl;
            targetForm << "                       ;%@@@@%::;.          " << std::endl;
            targetForm << "                      ;%@@@@%%:;;;. " << std::endl;
            targetForm << "                  ...;%@@@@@%%:;;;;,..    " << std::endl;
            targetForm.close();
        }
        else
            throw GradeTooLowException();
    }
}