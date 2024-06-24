#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _grade2Sign;
        const int _grade2Exec;

    
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        virtual ~Form();
 
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

    std::string getName() const;
    bool getSigned() const;
    int getGrade2Sign() const;
    int getGrade2Execute() const;

    void beSigned(const Bureaucrat &bureaucrat);
        
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif