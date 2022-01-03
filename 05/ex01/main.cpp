#include "Bureaucrat.hpp"
#include <iostream>

int
main()
{
  for (int i = 0; i <= 151; ++i) {
    try {
      Bureaucrat bill("Bill", i);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}