#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : Form("Robotomy Request Form", 72, 45)
  , target(target)
{
  std::cout << *this << "was created using user defined constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : Form(other)
{
  std::cout << *this << "was created using copy constructor\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << *this << "was destroyed\n";
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
  this->target = other.target;
  return (*this);
}

void
RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
  validateExecutionPermission(executor);
  int success = std::rand() % 2; // 50% chance of failure
  std::cout << "drilling noises!!\n";
  if (success) {
    std::cout << this->target << " has been robotomized successfully\n";
  } else
    std::cout << "robotomization failed\n";
}

RobotomyRequestForm::RobotomyRequestForm()
  : Form("Robotomy Request Form", 72, 45)
  , target("default")
{
  std::cout << *this << "was created using default constructor\n";
}
