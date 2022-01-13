#include "span.hpp"
#include <algorithm>
#include <ctime>
#include <gtest/gtest.h>
#include <list>

class SpanTest : public testing::Test
{
public:
  SpanTest()
    : size(5)
    , sp(size)
    , biggerSp(10000)
  {}
  void addElements()
  {
    const std::vector<int> vec = { 5, 3, 17, 9, 11 };
    sp.addNumbers(vec.begin(), vec.end());
  }
  void addElementsFromBiggerVector()
  {
    const std::vector<int> vec = { 5, 3, 17, 9, 11, 15, 20 };
    sp.addNumbers(vec.begin(), vec.end());
  }

  void addElementsNElements(int n)
  {
    std::srand(unsigned(std::time(nullptr)));
    std::vector<int> vec(n);
    std::generate(vec.begin(), vec.end(), std::rand);
    biggerSp.addNumbers(vec.begin(), vec.end());
  }

  const int size;
  Span sp;
  Span biggerSp;
};

TEST_F(SpanTest, emptySpan)
{
  EXPECT_THROW(sp.longestSpan(), std::out_of_range);
  EXPECT_THROW(sp.shortestSpan(), std::out_of_range);
}

TEST_F(SpanTest, oneElement)
{
  sp.addNumber(1);
  EXPECT_THROW(sp.longestSpan(), std::out_of_range);
  EXPECT_THROW(sp.shortestSpan(), std::out_of_range);
}

TEST_F(SpanTest, addMoreThanCapacity)
{
  addElements();
  EXPECT_THROW(sp.addNumber(5), std::out_of_range);
}

TEST_F(SpanTest, mimMaxSpan)
{
  addElements();
  EXPECT_EQ(sp.shortestSpan(), 2);
  EXPECT_EQ(sp.longestSpan(), 14);
}

TEST_F(SpanTest, AddFromBiggerVector)
{
  EXPECT_THROW(addElementsFromBiggerVector(), std::out_of_range);
}

TEST_F(SpanTest, HugeNumbers)
{
  addElementsNElements(1000);
  ASSERT_TRUE(biggerSp.shortestSpan() < biggerSp.longestSpan());
}