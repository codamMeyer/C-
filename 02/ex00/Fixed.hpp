#ifndef FIXED_H
#define FIXED_H

class Fixed
{
public:
  Fixed();
  Fixed(float n);
  Fixed(const Fixed& other);
  ~Fixed();
  Fixed& operator=(const Fixed& other);
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int rawNumber;
  const static int scale = 8;
};
#endif // FIXED_H