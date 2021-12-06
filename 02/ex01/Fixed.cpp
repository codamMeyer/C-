#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
  : rawNumber(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int n)
  : rawNumber(n << scale)
{
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float n)
  : rawNumber(n * factor)
{
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called\n";
}

Fixed&
Fixed::operator=(const Fixed& other)
{
  std::cout << "Assignation operator called\n";
  rawNumber = other.rawNumber;
  return *this;
}

int
Fixed::getRawBits(void) const
{
  return rawNumber;
}

void
Fixed::setRawBits(int const raw)
{
  rawNumber = raw;
}

float
Fixed::toFloat(void) const
{
  return (float)rawNumber / (float)factor;
}

int
Fixed::toInt(void) const
{
  return (rawNumber >> scale);
}

std::ostream&
operator<<(std::ostream& os, const Fixed& fixedPoint)
{
  (void)fixedPoint;
  return os << fixedPoint.toFloat();
}
