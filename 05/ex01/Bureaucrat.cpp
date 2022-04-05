#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade)
  : name(name)
  , maxGrade(1)
  , minGrade(150)
{
  setGrade(grade);
  std::cout << *this << " was created using user defined constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
  : name(other.name)
  , maxGrade(other.maxGrade)
  , minGrade(other.minGrade)
  , grade(other.grade)
{
  std::cout << *this << " was created using copy constructor\n";
}

Bureaucrat::~Bureaucrat()
{
  std::cout << *this << " was destroyed\n";
}

Bureaucrat&
Bureaucrat::operator=(const Bureaucrat& other)
{
  this->grade = other.grade;
  return *this;
}

const std::string&
Bureaucrat::getName() const
{
  return name;
}

int
Bureaucrat::getGrade() const
{
  return grade;
}

void
Bureaucrat::incrementGrade()
{
  setGrade(grade - 1);
}

void
Bureaucrat::decrementGrade()
{
  setGrade(grade + 1);
}

void
Bureaucrat::signForm(Form& form)
{
  try {
    form.beSigned(*this);
    std::cout << *this << " signs " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << this->name << " cannot sign " << form.getName()
	      << " because: " << e.what() << '\n';
  }
}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade is too low");
}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade is too high");
};

Bureaucrat::Bureaucrat()
  : name("Default")
  , maxGrade(1)
  , minGrade(150)
  , grade(1)
{
  std::cout << *this << " was created using default constructor\n";
}

void
Bureaucrat::setGrade(int grade)
{
  if (grade < maxGrade) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > minGrade) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade = grade;
}

std::ostream&
operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
  return os << Bureaucrat.getName() << ", bureaucrat grade "
	    << Bureaucrat.getGrade();
}
