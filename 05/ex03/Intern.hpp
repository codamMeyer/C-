#ifndef INTERN_H
#define INTERN_H
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
  Intern();
  Intern(const Intern& other);
  ~Intern();

  Form* makeForm(std::string formName, std::string target);

  Intern& operator=(const Intern& other);

private:
  typedef Form* (*GenerateForm)(std::string);
  struct FormPair
  {
    std::string name;
    Intern::GenerateForm generate;
  };

  Intern::GenerateForm avaiable[3];
  
  static Form* generateShrubberyCreationForm(std::string target);
  static Form* generateRobotomyRequestForm(std::string target);
  static Form* generatePresidentialPardonForm(std::string target);
  void populatePairs();

  static const int numForms = 3;
  FormPair availableForms[numForms];
};

#endif // INTERN_H