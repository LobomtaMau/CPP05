#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _grade2Sign;
        const int _grade2Exec;

    
    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw(){
                    return "Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw()  {
                    return "Grade is too low!";
                }
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw()  {
                    return "Form not signed";
                }
        };

    std::string getName() const;
    bool getSigned() const;
    int getGrade2Sign() const;
    int getGrade2Execute() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat &executer) const = 0;
        
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif