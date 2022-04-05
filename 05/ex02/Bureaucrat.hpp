#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <exception>
#include <string>

class Form;

class Bureaucrat
{
public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat& Bureaucrat);
  ~Bureaucrat();

  Bureaucrat& operator=(const Bureaucrat& other);

  const std::string& getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(Form& form);
  void executeForm(Form& form);

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

private:
  Bureaucrat();
  
  const std::string name;
  const int maxGrade;
  const int minGrade;
  int grade;

  void setGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif // BUREAUCRAT_H