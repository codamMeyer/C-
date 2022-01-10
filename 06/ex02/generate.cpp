#include "generate.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base*
generate(void)
{
  std::srand(std::time(NULL));
  static const int max = 3;

  switch (std::rand() % max) {
    case AType: {
      std::cout << "Generating: A\n";
      return new A();
    }
    case BType: {
      std::cout << "Generating: B\n";
      return new B();
    }
    case CType: {
      std::cout << "Generating: C\n";
      return new C();
    }
    default:
      return NULL;
  }
}
