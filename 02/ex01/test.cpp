#include "Fixed.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(FixedPointTest, Initialization_to_0)
{
  Fixed n;
  EXPECT_EQ(n.getRawBits(), 0);
}

TEST(FixedPointTest, Copy_constructor)
{
  Fixed a;
  Fixed n(a);

  EXPECT_EQ(n.getRawBits(), 0);
}

TEST(FixedPointTest, Assignation_operato)
{
  Fixed a;
  Fixed n;

  n = a;

  EXPECT_EQ(n.getRawBits(), 0);
}

TEST(FixedPointTest, setRawBits)
{
  Fixed n;

  n.setRawBits(1234);
  EXPECT_EQ(n.getRawBits(), 1234);
}

TEST(FixedPointTest, intConstructor)
{
  Fixed n(1);

  EXPECT_EQ(n.getRawBits(), 256);
}

TEST(FixedPointTest, FloatConstructor)
{
  float input = 1.1;
  Fixed n(input);

  EXPECT_EQ(n.getRawBits(), 281);
}

TEST(FixedPointTest, rawToInt)
{
  Fixed n(123);

  EXPECT_EQ(n.toInt(), 123);
}

TEST(FixedPointTest, rawToFloat_1)
{
  float input = 1234.432;
  Fixed n(input);

  EXPECT_FLOAT_EQ(n.toFloat(), 1234.43);
}

TEST(FixedPointTest, rawToFloat_2)
{
  GTEST_SKIP(); // TODO Check precision
  float input = 42.42;
  Fixed n(input);

  std::cout << n << std::endl;

  EXPECT_FLOAT_EQ(n.toFloat(), 42.4219);
}
