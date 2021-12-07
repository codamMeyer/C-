#include "Point.hpp"

Point::Point()
  : x(0)
  , y(0)
{}

Point::Point(const Point& other)
  : x(other.x)
  , y(other.y)
{}

Point::Point(const float x, const float y)
  : x(x)
  , y(y)
{}

Point::~Point() {}

bool
Point::operator==(const Point& other) const
{
  return (x == other.getX()) && (y == other.getY());
}

const Fixed&
Point::getX() const
{
  return x;
}

const Fixed&
Point::getY() const
{
  return y;
}
