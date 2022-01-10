#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "generate.hpp"
#include "identify.hpp"
#include <iostream>
#include <unistd.h>

int
main()
{
  for (int i = 0; i < 10; ++i) {
    Base* base = generate();
    std::cout << "Reference: ";
    identify(*base);
    std::cout << "Pointer: ";
    identify(base);
    std::cout << '\n';
    delete base;
    sleep(5);
  }
}
