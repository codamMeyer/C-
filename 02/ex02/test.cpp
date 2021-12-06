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
  // std::cout << "----> " << n << std::endl;

  EXPECT_EQ(n.getRawBits(), 282);
}

TEST(FixedPointTest, rawToInt)
{
  Fixed n(1);

  EXPECT_EQ(n.toInt(), 1);
}

TEST(FixedPointTest, rawToFloat_1)
{
  float input = 1234.432;
  Fixed n(input);

  // std::cout << "----> " << n << std::endl;

  EXPECT_NEAR(n.toFloat(), 1234.43, 0.01);
}

TEST(FixedPointTest, rawToFloat_2)
{
  float input = 42.42;
  Fixed n(input);

  // std::cout << "----> " << n << std::endl;
  EXPECT_NEAR(n.toFloat(), 42.4219, 0.0001);
}

TEST(FixedPointTest, smallerThan)
{
  float input1 = 42.42;
  float input2 = 42.43;
  Fixed smaller(input1);
  Fixed bigger(input2);

  EXPECT_TRUE(smaller < bigger);
  EXPECT_TRUE(smaller <= bigger);
}

TEST(FixedPointTest, smallerThanWithSameNumber)
{
  float input1 = 42.42;
  Fixed smaller(input1);
  Fixed bigger(input1);

  EXPECT_FALSE(smaller < bigger);
  EXPECT_TRUE(smaller <= bigger);
}

TEST(FixedPointTest, biggerThan)
{
  float input1 = 42.42;
  float input2 = 42.43;
  Fixed smaller(input1);
  Fixed bigger(input2);

  EXPECT_TRUE(bigger > smaller);
  EXPECT_TRUE(bigger >= smaller);
}

TEST(FixedPointTest, equal)
{
  float input1 = 42.42;
  float input2 = 42.43;
  Fixed smaller(input1);
  Fixed bigger(input2);

  EXPECT_TRUE(bigger != smaller);
  EXPECT_TRUE(smaller == smaller);
}

TEST(FixedPointTest, preIncrement)
{
  Fixed n;

  EXPECT_EQ((++n).toFloat(), 0.00390625);
}

TEST(FixedPointTest, postIncrement)
{
  Fixed n;

  EXPECT_EQ((n++).toFloat(), 0.0);
  EXPECT_EQ(n.toFloat(), 0.00390625);
}

TEST(FixedPointTest, postDecrement)
{
  Fixed n;

  n++;
  EXPECT_EQ((n--).toFloat(), 0.00390625);
  EXPECT_EQ(n.toFloat(), 0.0);
}

TEST(FixedPointTest, preDecrement)
{
  Fixed n;

  n++;
  EXPECT_EQ(n.toFloat(), 0.00390625);
  EXPECT_EQ((--n).toFloat(), 0.0);
}

TEST(FixedPointTest, sum)
{
  Fixed a(2);
  Fixed b(2);

  EXPECT_EQ((a + b).toInt(), 4);
}

TEST(FixedPointTest, sumNegativeNumbers)
{
  Fixed a(-2);
  Fixed b(-4);

  EXPECT_EQ((a + b).toInt(), -6);
}

TEST(FixedPointTest, sub)
{
  Fixed a(4);
  Fixed b(2);

  EXPECT_EQ((a - b).toInt(), 2);
}

TEST(FixedPointTest, subNegativeNumbers)
{
  Fixed a(-2);
  Fixed b(-4);

  EXPECT_EQ((a - b).toInt(), 2);
}

TEST(FixedPointTest, mult)
{
  Fixed a(4);
  Fixed b(2);

  EXPECT_EQ((a * b).toInt(), 8);
}

TEST(FixedPointTest, multNegativeNumbers)
{
  Fixed a(-2);
  Fixed b(-4);

  EXPECT_EQ((a * b).toInt(), 8);
}

TEST(FixedPointTest, div)
{
  Fixed a(4);
  Fixed b(2);

  EXPECT_EQ((a / b).toInt(), 2);
}
