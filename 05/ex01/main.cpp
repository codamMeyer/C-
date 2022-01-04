#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void
tryToCreateForm(std::string name, int gradeToSign, int gradeToExecute)
{
  try {
    std::cout << "\n\nTrying to create form: " << name << "\n"
	      << "Grade to sign: " << gradeToSign << "\n"
	      << "Grade to execute: " << gradeToExecute << "\n\n";

    Form(name, gradeToSign, gradeToExecute);
  } catch (std::exception& e) {
    std::cout << "Execption message: " << e.what() << "\n\n";
  }
}

int
main()
{
  tryToCreateForm("Low Grade Form", 160, 50);
  tryToCreateForm("High Grade Form", 20, 0);
  tryToCreateForm("Silly Form", 20, 21);
  std::cout << "\n\n";

  Form SillyForm("Silly Form", 20, 50);
  std::cout << "\n\n";
  Bureaucrat("Bill", 30).signForm(SillyForm); // grade is too low
  std::cout << "Form status: " << SillyForm.getStatus() << "\n\n";
  Bureaucrat("Jack", 2).signForm(SillyForm);
  std::cout << "Form status: " << SillyForm.getStatus() << "\n\n";
}