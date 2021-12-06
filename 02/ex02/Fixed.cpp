#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed()
  : rawNumber(0)
{}

Fixed::Fixed(const int n)
  : rawNumber(n << scale)
{}

Fixed::Fixed(const float n)
  : rawNumber(roundf(n * factor))
{}

Fixed::Fixed(const Fixed& other)
{
  *this = other;
}

Fixed::~Fixed() {}

Fixed&
Fixed::operator=(const Fixed& other)
{
  rawNumber = other.rawNumber;
  return *this;
}

bool
Fixed::operator<(const Fixed& other)
{
  return (getRawBits() < other.getRawBits());
}

bool
Fixed::operator<=(const Fixed& other)
{
  return (getRawBits() <= other.getRawBits());
}

bool
Fixed::operator>(const Fixed& other)
{
  return (getRawBits() > other.getRawBits());
}

bool
Fixed::operator>=(const Fixed& other)
{
  return (getRawBits() >= other.getRawBits());
}

bool
Fixed::operator==(const Fixed& other)
{
  return (getRawBits() == other.getRawBits());
}

bool
Fixed::operator!=(const Fixed& other)
{
  return (getRawBits() != other.getRawBits());
}

Fixed&
Fixed::operator++()
{
  ++rawNumber;
  return *this;
}

Fixed
Fixed::operator++(int)
{
  Fixed old = *this;
  operator++();
  return old;
}

Fixed&
Fixed::operator--()
{
  --rawNumber;
  return *this;
}

Fixed
Fixed::operator--(int)
{
  Fixed old = *this;
  operator--();
  return old;
}

Fixed
Fixed::operator+(const Fixed& other)
{
  Fixed sum;
  sum.setRawBits(this->rawNumber + other.rawNumber);

  return sum;
}

Fixed
Fixed::operator-(const Fixed& other)
{
  Fixed sub;
  sub.setRawBits(this->rawNumber - other.rawNumber);

  return sub;
}

Fixed
Fixed::operator*(const Fixed& other)
{
  Fixed mult;
  int lhs = this->rawNumber >> (scale / 2);
  int rhs = other.rawNumber >> (scale / 2);
  mult.rawNumber = lhs * rhs;
  return mult;
}

Fixed
Fixed::operator/(const Fixed& other)
{
  Fixed div;
  long long int lhs = this->rawNumber << scale;
  long long int rhs = other.rawNumber;
  div.rawNumber = lhs / rhs;
  return div;
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
