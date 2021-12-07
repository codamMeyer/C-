#ifndef POINT_H
#define POINT_H
#include "Fixed.hpp"

class Point
{
public:
  Point();
  Point(const Point& other);
  Point(const float x, const float y);
  ~Point();

  bool operator==(const Point& other) const;

  const Fixed& getX() const;
  const Fixed& getY() const;

private:
  const Fixed x;
  const Fixed y;
};
#endif // POINT_H