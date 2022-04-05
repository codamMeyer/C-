#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  : Form("Presidential Pardon Form", 25, 5)
  , target(target)
{
  std::cout << *this << "was created using user defined constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(
  const PresidentialPardonForm& other)
  : Form(other)
{
  std::cout << *this << "was created using copy constructor\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << *this << "was destroyed\n";
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
  this->target = other.target;
  return (*this);
}

void
PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
  validateExecutionPermission(executor);
  std::cout << this->target << " has been pardoned by Zafod Beeblebrox\n";
}

PresidentialPardonForm::PresidentialPardonForm()
  : Form("Presidential Pardon Form", 25, 5)
  , target("default")
{
  std::cout << *this << "was created using default constructor\n";
}
