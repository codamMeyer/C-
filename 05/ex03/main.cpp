#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int
main()
{
  Intern randomIntern;
  Form* ref = randomIntern.makeForm("robotomy request", "Dave");
  delete ref;
}
