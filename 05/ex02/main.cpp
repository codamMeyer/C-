#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int
main()
{
  std::cout << "Creating Shrubbery Form:\n";
  ShrubberyCreationForm ShrubberyForm("home");
  std::cout << "\n\n";
  std::cout << "Creating Robotomy Form:\n";
  RobotomyRequestForm RobotomyForm("Greg");
  std::cout << "\n\n";
  std::cout << "Creating Presidential Form:\n";
  PresidentialPardonForm PresidentialForm("Greg");
  std::cout << "\n\n";

  Bureaucrat bob("Bob", 20);
  Bureaucrat bill("Bill", 30);
  Bureaucrat jack("Jack", 147);

  bob.signForm(PresidentialForm);
  bob.executeForm(PresidentialForm);

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
