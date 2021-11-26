#include "Karen.hpp"
#include <iostream>

int
main(int argc, const char* argv[])
{
  std::cout << "\nLet's make Karen complain\n\n";
  if (argc == 1)
    Karen().complain("");
  else
    Karen().complain(argv[1]);
}