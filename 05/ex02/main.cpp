#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int
main()
{
  ShrubberyCreationForm ShrubberyForm("home");
  RobotomyRequestForm RobotomyForm("Greg");
  std::cout << "\n\n";

  Bureaucrat bill("Bill", 30);
  Bureaucrat jack("Jack", 147);
  jack.signForm(ShrubberyForm);
  bill.executeForm(ShrubberyForm);
  bill.signForm(ShrubberyForm);
  bill.executeForm(ShrubberyForm);

  bill.signForm(RobotomyForm);
  bill.executeForm(RobotomyForm);
  bill.executeForm(RobotomyForm);
  bill.executeForm(RobotomyForm);
  bill.executeForm(RobotomyForm);
  bill.executeForm(RobotomyForm);
}
