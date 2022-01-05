#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Form
{
public:
  Form();
  Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
  Form(const Form& other);
  virtual ~Form();

  Form& operator=(const Form& other);

  const std::string& getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  std::string getStatus() const;
  bool getSignedBoolStatus() const;
  void beSigned(const Bureaucrat& Bureaucrat);

  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooLowException : public std::exception
  {
  public:
    virtual const char* what() const throw();
  };

  class GradeTooHighException : public std::exception
  {
  public:
    virtual const char* what() const throw();
  };
  class UnsignedFormException : public std::exception
  {
  public:
    virtual const char* what() const throw();
  };

protected:
  void validateExecutionPermission(const Bureaucrat& bureaucrat) const;

private:
  bool isSigned;
  const std::string name;
  const int requiredGradeToSign;
  const int requiredGradeToExecute;
  const int maxGrade;
  const int minGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif // FORM_H
