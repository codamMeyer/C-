#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

void
tryToCreateBureaucrat(const std::string& name, int grade)
{
  std::cout << "\e[1;33mCreating Bureaucrat with grade " << grade << '\n'
	    << "\e[0m";

  try {
    Bureaucrat bill(name, grade);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << '\n';
}

int
main()
{
  tryToCreateBureaucrat("A", 0);
  tryToCreateBureaucrat("B", 150);
  tryToCreateBureaucrat("C", 10);
  tryToCreateBureaucrat("D", 75);

  tryToCreateBureaucrat("E", -1);
  tryToCreateBureaucrat("F", 200);
}