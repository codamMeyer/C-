#include "easyfind.hpp"
#include <gtest/gtest.h>
#include <list>

TEST(easyfindTest, cantFindInVector)
{
  std::vector<int> vec(5, 0);
  ASSERT_EQ(vec.end(), easyfind(vec, 1));
}

TEST(easyfindTest, findInVector)
{
  std::vector<int> vec(5, 0);
  vec.push_back(1); // insert at index 5
  ASSERT_NE(vec.end(), easyfind(vec, 1));
}

TEST(easyfindTest, cantFindInList)
{
  std::list<int> l{ 0, 0, 0 };
  ASSERT_EQ(l.end(), easyfind(l, 1));
}

TEST(easyfindTest, findInList)
{
  std::list<int> l{ 0, 0, 1 };
  ASSERT_NE(l.end(), easyfind(l, 1));
}
