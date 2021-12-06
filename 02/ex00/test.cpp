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