#include "Point.hpp"
#include "bsp.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(bspFunction, inside)
{
  Point A(0.0, 0.0);
  Point B(0.0, 20.0);
  Point C(30.0, 10.0);
  Point P(15.0, 10.0);
  EXPECT_TRUE(bsp(A, B, C, P));
}

TEST(bspFunction, outside)
{
  Point A(0.0, 0.0);
  Point B(0.0, 20.0);
  Point C(30.0, 10.0);
  Point P(15.0, 35.0);
  EXPECT_FALSE(bsp(A, B, C, P));
}

TEST(bspFunction, outsideOnEdge)
{
  Point A(0.0, 0.0);
  Point B(0.0, 20.0);
  Point C(30.0, 10.0);
  EXPECT_FALSE(bsp(A, B, C, A));
  EXPECT_FALSE(bsp(A, B, C, B));
  EXPECT_FALSE(bsp(A, B, C, C));

}

TEST(bspFunction, notTriangle)
{
  Point A(0.0, 0.0);
  Point B(2.0, 0.0);
  Point C(4.0, 0.0);
  Point Point(3.0, 0.0);

  EXPECT_FALSE(bsp(A, B, C, A));
  EXPECT_FALSE(bsp(A, B, C, B));
  EXPECT_FALSE(bsp(A, B, C, C));
  EXPECT_FALSE(bsp(A, B, C, Point));
}