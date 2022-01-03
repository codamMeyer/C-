#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
  : name("Default")
  , maxGrade(1)
  , minGrade(150)
  , grade(1)
{
  std::cout << *this << " was created using deafault constructor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
  : name(name)
  , maxGrade(1)
  , minGrade(150)
{
  setGrade(grade);
  std::cout << *this << " was created using user defined constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& Bureaucrat)
  : name(Bureaucrat.name)
  , maxGrade(Bureaucrat.maxGrade)
  , minGrade(Bureaucrat.minGrade)
  , grade(Bureaucrat.grade)
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
Bureaucrat::setGrade(int grade)
{
  if (grade < maxGrade) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > minGrade) {
    throw Bureaucrat::GradeTooLowException();
  } else {
    this->grade = grade;
  }
}

std::ostream&
operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
  return os << Bureaucrat.getName() << ", bureaucrat grade "
	    << Bureaucrat.getGrade();
}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("The lowest grade is 150");
}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("The highest grade is 1");
};
