#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _isSigned(false), _grade2Sign(150), _grade2Exec(150) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _grade2Sign(gradeToSign), _grade2Exec(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _grade2Sign(other._grade2Sign), _grade2Exec(other._grade2Exec) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _isSigned;
}

int AForm::getGrade2Sign () const {
    return _grade2Sign;
}

int AForm::getGrade2Execute() const {
    return _grade2Exec;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _grade2Sign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << ", form status: " << (form.getSigned() ? "signed" : "not signed")
    << ", grade required to sign: " << form.getGrade2Sign()
    << ", grade required to execute: " << form.getGrade2Execute();
    return os;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!_isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _grade2Exec) {
        throw GradeTooLowException();
    }
}