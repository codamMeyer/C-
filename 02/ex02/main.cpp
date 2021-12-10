#include "Fixed.hpp"
#include <iostream>

int
main()
{
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a.getRawBits() << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a.getRawBits() << std::endl;
  std::cout << a-- << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << Fixed::min(a, b) << std::endl;

  Fixed c(14.5f);
  Fixed d(20.4f);
  std::cout << c << " < " << d << " = " << (c < d) << std::endl;
  std::cout << c << " <= " << d << " = " << (c <= d) << std::endl;
  std::cout << c << " > " << d << " = " << (c > d) << std::endl;
  std::cout << c << " >= " << d << " = " << (c >= d) << std::endl;
  std::cout << c << " == " << d << " = " << (c == d) << std::endl;
  std::cout << c << " != " << d << " = " << (c != d) << std::endl;
  std::cout << c << " + " << d << " = " << (c + d) << std::endl;
  std::cout << c << " - " << d << " = " << (c - d) << std::endl;
  std::cout << c << " / " << d << " = " << (c / d) << std::endl;
  std::cout << c << " * " << d << " = " << (c * d) << std::endl;

  return 0;
}