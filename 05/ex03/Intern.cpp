#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
  std::cout << "Intern was created using default constructor\n";
  populatePairs();
  avaiable[0] = &Intern::generateShrubberyCreationForm;
}

Intern::Intern(const Intern& other)
{
  *this = other;
  std::cout << "Intern was created using copy constructor\n";
}

Intern::~Intern()
{
  std::cout << "Intern was destroyed\n";
}

Form*
Intern::makeForm(std::string formName, std::string target)
{
  for (int i = 0; i < numForms; ++i) {
    if (formName == availableForms[i].name) {
      return availableForms[i].generate(target);
    }
  }
  std::cout << formName << ": form not found!\nAvailable Options:\n";
  for (int i = 0; i < numForms; ++i) {
    std::cout << "  - " << availableForms[i].name << "\n";
  }
  return NULL;
}

Intern&
Intern::operator=(const Intern&)
{
  return *this;
}

Form*
Intern::generateShrubberyCreationForm(std::string target)
{
  return new ShrubberyCreationForm(target);
}

Form*
Intern::generateRobotomyRequestForm(std::string target)
{
  return new RobotomyRequestForm(target);
}

Form*
Intern::generatePresidentialPardonForm(std::string target)
{
  return new PresidentialPardonForm(target);
}

void
Intern::populatePairs()
{
  availableForms[0].name = "shrubbery creation";
  availableForms[0].generate = &Intern::generateShrubberyCreationForm;
  availableForms[1].name = "robotomy request";
  availableForms[1].generate = &Intern::generateRobotomyRequestForm;
  availableForms[2].name = "presidential pardon";
  availableForms[2].generate = &Intern::generatePresidentialPardonForm;
}
