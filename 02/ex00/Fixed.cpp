#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
  : rawNumber(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
  : rawNumber(other.rawNumber)
{
  std::cout << "Copy constructor called\n";
}

Fixed::~Fixed()
{
  std::cout << "Destructor called\n";
}

Fixed&
Fixed::operator=(const Fixed& other)
{
  std::cout << "Assignation operator called\n";
  rawNumber = other.getRawBits();
  return *this;
}

int
Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called\n";
  return rawNumber;
}

void
Fixed::setRawBits(int const raw)
{
  std::cout << "setRawBits member function called\n";
  rawNumber = raw;
}
