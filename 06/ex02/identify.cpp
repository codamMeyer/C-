#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
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
  try {
    A a = dynamic_cast<A&>(p);
    std::cout << "A\n";
  } catch (std::exception e) {
  }
  try {
    B b = dynamic_cast<B&>(p);
    std::cout << "B\n";
  } catch (std::exception e) {
  }
  try {
    C c = dynamic_cast<C&>(p);
    std::cout << "C\n";
  } catch (std::exception e) {
  }
}
