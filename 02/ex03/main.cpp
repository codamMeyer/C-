#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

void
printResult(bool result)
{
  if (result == true)
    std::cout << "is inside\n";
  else
    std::cout << "is outside\n";
}

int
main()
{
  Point A(0.0, 0.0);
  Point B(20.0, 0.0);
  Point C(10.0, 30.0);
  Point PointInside(10.0, 15.0);
  Point PointOutside(40.0, 50.0);

  printResult(bsp(A, B, C, PointInside));
  printResult(bsp(A, B, C, PointOutside));

  return 0;
}