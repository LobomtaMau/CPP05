#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _grade2Sign(gradeToSign), _grade2Exec(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _grade2Sign(other._grade2Sign), _grade2Exec(other._grade2Exec) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}



