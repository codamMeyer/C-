#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void
identify(Base* p)
{
  if (dynamic_cast<A*>(p) != NULL) {
    std::cout << "A\n";
  } else if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "B\n";
  } else if (dynamic_cast<C*>(p) != NULL) {
    std::cout << "C\n";
  }
}

void
identify(Base& p)
{
  if (dynamic_cast<A*>(&p) != NULL) {
    std::cout << "A\n";
  } else if (dynamic_cast<B*>(&p) != NULL) {
    std::cout << "B\n";
  } else if (dynamic_cast<C*>(&p) != NULL) {
    std::cout << "C\n";
  }
}
