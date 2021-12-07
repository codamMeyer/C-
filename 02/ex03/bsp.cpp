#include "bsp.hpp"

float
absValue(float n)
{
  if (n < 0) {
    return n *= -1;
  } else {
    return n;
  }
}

float
getArea(Point const a, Point const b, Point const c)
{
  const float xA = a.getX().toFloat();
  const float yA = a.getY().toFloat();
  const float xB = b.getX().toFloat();
  const float yB = b.getY().toFloat();
  const float xC = c.getX().toFloat();
  const float yC = c.getY().toFloat();

  const float sideBC = yB - yC;
  const float sideCA = yC - yA;
  const float sideAB = yA - yB;

  return absValue((xA * sideBC + xB * sideCA + xC * sideAB) / 2.0);
}

bool
bsp(Point const a, Point const b, Point const c, Point const point)
{
  if (a == point || b == point || c == point)
    return false;

  const float abcArea = getArea(a, b, c);
  const float pbcArea = getArea(point, b, c);
  const float pacArea = getArea(point, a, c);
  const float pbaArea = getArea(point, b, a);

  return abcArea == pbcArea + pacArea + pbaArea;
}