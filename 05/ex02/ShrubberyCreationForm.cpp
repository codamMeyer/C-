#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iomanip>
#include <iosfwd>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  : Form("Shrubbery Creation Form", 145, 137)
  , target(target)
  , fileName(target + "_shrubbery")
{
  std::cout << *this << "was created using user defined constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
  : Form(other)
{
  std::cout << *this << "was created using copy constructor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << *this << "was destroyed\n";
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
  this->target = other.target;
  return (*this);
}

void
ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
  static const std::string tree = "                         \n"
				  "         A\n"
				  "        d$b\n"
				  "      .d$$$b.\n"
				  "    .d$i$$$$$b.\n"
				  "       d$$@b\n"
				  "      d$$$$ib\n"
				  "    .d$$$$$$$b\n"
				  "  .d$$@$$$$$$$ib.\n"
				  "      d$$i$$b\n"
				  "     d$$$$$@$b\n"
				  "  .d$@$$$$$$$$@b.\n"
				  ".d$$$$i$$$$$$$$$$b.\n"
				  "        ###\n"
				  "        ###\n"
				  "        ###\n";

  validateExecutionPermission(executor);
  std::ofstream file(fileName.data());
  if (!file.is_open()) {
    std::cout << "Coulnd't open the output file" << std::endl;
    return;
  }
  file << tree;
}

ShrubberyCreationForm::ShrubberyCreationForm()
  : Form("Shrubbery Creation Form", 145, 137)
  , target("default")
  , fileName("default_shrubbery")
{
  std::cout << *this << "was created using default constructor\n";
}
