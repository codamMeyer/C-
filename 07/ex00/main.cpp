#include "whatever.hpp"
#include <assert.h>
#include <iostream>

int
main(void)
{
  int a = 2;
  int b = 3;

  std::cout << "\nbefore: a = " << a << ", b = " << b << std::endl;
  std::cout << "swap(a, b)" << std::endl;
  ::swap(a, b);
  std::cout << "after:  a = " << a << ", b = " << b << std::endl;
  std::cout << "\nmin( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  assert(a == 3);
  assert(b == 2);
  assert(::min(a, b) == b);
  assert(::max(a, b) == a);


  std::string c = "chaine1";
  std::string d = "chaine2";

  std::cout << "\nbefore: c = " << c << ", d = " << d << std::endl;
  std::cout << "swap(c, d)" << std::endl;
  ::swap(c, d);
  std::cout << "after:  c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  assert(c == "chaine2");
  assert(d == "chaine1");
  assert(::min(c, d) == d);
  assert(::max(c, d) == c);

  return 0;
}
