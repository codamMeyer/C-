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
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int rawNumber;
  const static int scale = 8;
  const static int factor = 1 << scale;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);

#endif // FIXED_H
