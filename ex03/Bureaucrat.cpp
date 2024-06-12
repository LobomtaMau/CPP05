#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    checkGrade(_grade);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other) {
    if(this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::checkGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() { 
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade() {
    checkGrade(_grade + 1);
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureacrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << "\n";
    }
    catch (std::exception &e) {
        std::cout << _name << " couldn’t sign " << form.getName() << " because "
        << e.what() << "\n";
    }
}

void Bureaucrat::executeForm(const AForm &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << "\n";
    }
    catch (std::exception &e) {
        std::cout << _name << " couldn’t execute " << form.getName() << " because "
        << e.what() << "\n";
    }
}