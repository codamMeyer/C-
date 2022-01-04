#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
  : isSigned(false)
  , name("default")
  , requiredGradeToSign(1)
  , requiredGradeToExecute(1)
  , maxGrade(1)
  , minGrade(150)
{
  std::cout << *this << " was created using deafault constructor\n";
}

Form::Form(std::string name,
	   int requiredGradeToSign,
	   int requiredGradeToExecute)
  : isSigned(false)
  , name(name)
  , requiredGradeToSign(requiredGradeToSign)
  , requiredGradeToExecute(requiredGradeToExecute)
  , maxGrade(1)
  , minGrade(150)
{
  if (requiredGradeToSign > minGrade || requiredGradeToExecute > minGrade) {
    throw(Form::GradeTooLowException());
  } else if (requiredGradeToSign < maxGrade ||
	     requiredGradeToExecute < maxGrade) {
    throw(Form::GradeTooHighException());
  }
  std::cout << *this << "Was created using user defined constructor\n";
}

Form::Form(const Form& other)
  : isSigned(other.isSigned)
  , name(other.name)
  , requiredGradeToSign(other.requiredGradeToSign)
  , requiredGradeToExecute(other.requiredGradeToExecute)
  , maxGrade(1)
  , minGrade(150)
{
  std::cout << *this << "Was created using copy constructor\n";
}

Form::~Form()
{
  std::cout << *this << "Was destroyed\n";
}

Form&
Form::operator=(const Form& other)
{
  isSigned = other.isSigned;
  return *this;
}

const std::string&
Form::getName() const
{
  return name;
}

int
Form::getGradeToSign() const
{
  return requiredGradeToSign;
}

int
Form::getGradeToExecute() const
{
  return requiredGradeToExecute;
}

std::string
Form::getStatus() const
{
  if (isSigned) {
    return "Signed";
  } else {
    return "Not Signed";
  }
}

bool
Form::getSignedBoolStatus() const
{
  return isSigned;
}

void
Form::beSigned(const Bureaucrat& Bureaucrat)
{
  if (Bureaucrat.getGrade() <= requiredGradeToSign) {
    isSigned = true;
  } else {
    throw Form::GradeTooLowException();
  }
}

const char*
Form::GradeTooLowException::what() const throw()
{
  return ("Grade is too low");
}

const char*
Form::GradeTooHighException::what() const throw()
{
  return ("Grade is too high");
};

std::ostream&
operator<<(std::ostream& os, const Form& Form)
{
  return os << "Form Name: " << Form.getName()
	    << "\nGrade To Sign: " << Form.getGradeToSign()
	    << "\nGrade to Execute: " << Form.getGradeToExecute()
	    << "\nStatus: " << Form.getStatus() << std::endl;
}
