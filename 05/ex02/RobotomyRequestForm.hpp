#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

  void execute(Bureaucrat const& executor) const;

private:
  std::string target;
};

#endif // ROBOTOMYREQUESTFORM_H