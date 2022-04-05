#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

  void execute(Bureaucrat const& executor) const;

private:
  ShrubberyCreationForm();
  std::string target;
  std::string fileName;
};

#endif // SHRUBBERYCREATIONFORM_H