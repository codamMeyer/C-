#include "Karen.hpp"
#include <iostream>

int
main()
{
  std::cout << "\nLet's make Karen complain\n\n";
  std::cout << "\n[INVALID COMPLAIN]\n";
  Karen().complain("Some invalid complain level");
  std::cout << "\n[DEBUG]\n";
  Karen().complain("DEBUG");
  std::cout << "\n[INFO]\n";
  Karen().complain("INFO");
  std::cout << "\n[WARNING]\n";
  Karen().complain("WARNING");
  std::cout << "\n[ERROR]\n";
  Karen().complain("ERROR");
}