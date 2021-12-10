#include "Fixed.hpp"
#include <iostream>
#include <math.h>

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
  : rawNumber(roundf(n * factor))
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
  rawNumber = other.rawNumber;
  return *this;
}

bool
Fixed::operator<(const Fixed& other) const
{
  return (getRawBits() < other.getRawBits());
}

bool
Fixed::operator<=(const Fixed& other) const
{
  return (getRawBits() <= other.getRawBits());
}

bool
Fixed::operator>(const Fixed& other) const
{
  return (getRawBits() > other.getRawBits());
}

bool
Fixed::operator>=(const Fixed& other) const
{
  return (getRawBits() >= other.getRawBits());
}

bool
Fixed::operator==(const Fixed& other) const
{
  return (getRawBits() == other.getRawBits());
}

bool
Fixed::operator!=(const Fixed& other) const
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
Fixed::operator+(const Fixed& other) const
{
  Fixed sum;
  sum.setRawBits(this->rawNumber + other.rawNumber);

  return sum;
}

Fixed
Fixed::operator-(const Fixed& other) const
{
  Fixed sub;
  sub.setRawBits(this->rawNumber - other.rawNumber);

  return sub;
}

Fixed
Fixed::operator*(const Fixed& other) const
{
  Fixed mult;
  const long long int lhs = this->rawNumber;
  const long long int rhs = other.rawNumber;
  mult.rawNumber = lhs * rhs >> scale;

  return mult;
}

Fixed
Fixed::operator/(const Fixed& other) const
{
  Fixed div;
  const long long int lhs = this->rawNumber << scale;
  const long long int rhs = other.rawNumber;
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

Fixed&
Fixed::min(Fixed& lhs, Fixed& rhs)
{
  if (lhs.rawNumber < rhs.rawNumber) {
    return lhs;
  } else {
    return rhs;
  }
}

Fixed&
Fixed::max(Fixed& lhs, Fixed& rhs)
{
  if (lhs.rawNumber > rhs.rawNumber) {
    return lhs;
  } else {
    return rhs;
  }
}
const Fixed&
Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
  if (lhs.rawNumber < rhs.rawNumber) {
    return lhs;
  } else {
    return rhs;
  }
}

const Fixed&
Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
  if (lhs.rawNumber > rhs.rawNumber) {
    return lhs;
  } else {
    return rhs;
  }
}

std::ostream&
operator<<(std::ostream& os, const Fixed& fixedPoint)
{
  (void)fixedPoint;
  return os << fixedPoint.toFloat();
}
