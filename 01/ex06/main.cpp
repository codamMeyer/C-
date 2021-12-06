#include "Karen.hpp"
#include <iostream>

int
main(int argc, const char* argv[])
{
  if (argc == 1)
    Karen().complain("");
  else
    Karen().complain(argv[1]);
}