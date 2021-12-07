#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
public:
  Fixed();
  Fixed(const int n);
  Fixed(const float n);
  Fixed(const Fixed& other);
  ~Fixed();
  Fixed& operator=(const Fixed& other);

  bool operator<(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator>(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed& operator++();	 // pre-increment
  Fixed operator++(int); // post-increment
  Fixed& operator--();	 // pre-decrement
  Fixed operator--(int); // post-decrement

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
  static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
  static Fixed& min(Fixed& lhs, Fixed& rhs);
  static Fixed& max(Fixed& lhs, Fixed& rhs);

private:
  int rawNumber;
  const static int scale = 8;
  const static int factor = 1 << scale;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);

#endif // FIXED_H
