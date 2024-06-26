#include "Form.hpp"

Form::Form()
    : _name("default"), _isSigned(false), _grade2Sign(150), _grade2Exec(150) {
}

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

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _isSigned;
}

int Form::getGrade2Sign () const {
    return _grade2Sign;
}

int Form::getGrade2Execute() const {
    return _grade2Exec;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _grade2Sign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << form.getName() << ", form status: " << (form.getSigned() ? "signed" : "not signed")
    << ", grade required to sign: " << form.getGrade2Sign()
    << ", grade required to execute: " << form.getGrade2Execute();
    return os;
}

