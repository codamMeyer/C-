#include "bsp.hpp"

static float
absValue(float n)
{
  if (n < 0) {
    return n *= -1;
  } else {
    return n;
  }
}

static float
getArea(Point const a, Point const b, Point const c)
{
  const float xA = a.getX().toFloat();
  const float yA = a.getY().toFloat();
  const float xB = b.getX().toFloat();
  const float yB = b.getY().toFloat();
  const float xC = c.getX().toFloat();
  const float yC = c.getY().toFloat();

  const float difBC = yB - yC;
  const float difCA = yC - yA;
  const float difAB = yA - yB;

  //  explanation with drawing
  //  https://www.cuemath.com/geometry/area-of-triangle-in-coordinate-geometry/
  return absValue((xA * difBC + xB * difCA + xC * difAB) / 2.0);
}

bool
bsp(Point const a, Point const b, Point const c, Point const point)
{
  const float abcArea = getArea(a, b, c);
  const float pbcArea = getArea(point, b, c);
  const float pacArea = getArea(point, a, c);
  const float pbaArea = getArea(point, b, a);

  if (abcArea == 0 || pbcArea == 0 || pacArea == 0 || pbaArea == 0) {
    return false;
  }
  return abcArea == pbcArea + pacArea + pbaArea;
}