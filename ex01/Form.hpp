#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
        std::string _name;
        bool _isSigned;
        const int _grade2Sign;
        const int _grade2Exec;

    
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        virtual ~Form();

    class GradeTooLowException : public std::runtime_error {
        public:
            GradeTooLowException() : std::runtime_error("Grade too low!") {}
    };

    class GradeTooHighException : public std::runtime_error {
        public:
            GradeTooHighException() : std::runtime_error("Grade too high!") {}
    };

    std::string getName() const;
    bool getSigned() const;
    int getGrade2Sign() const;
    int getGrade2Execute() const;

    void beSigned(const Bureaucrat &bureaucrat);
        
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif