#include "Array.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(ArrayTest, emptyArray)
{
  Array<int> array;
  ASSERT_EQ(array.size(), 0);
  EXPECT_THROW(array[0], std::out_of_range);
}

TEST(ArrayTest, sizeOneArray)
{
  Array<int> array(1);
  ASSERT_EQ(array.size(), 1);
  array[0] = 5;
  ASSERT_EQ(array[0], 5);
  EXPECT_THROW(array[1], std::out_of_range);
  EXPECT_THROW(array[5], std::out_of_range);
}

TEST(ArrayTest, allocNewArray)
{
  const int size = 5;
  Array<int> array(size);
  ASSERT_EQ(array.size(), size);
  for (int i = 0; i < size; ++i) {
    array[i] = i;
  }
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], i);
  }
}

TEST(ArrayTest, deepCopyArray)
{
  const int size = 5;
  Array<int> array(size);
  Array<int> copy(array);
  ASSERT_EQ(array.size(), size);
  ASSERT_EQ(copy.size(), size);
  for (int i = 0; i < size; ++i) {
    array[i] = i;
  }
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], i);
  }

  // checking if copy array isn't modified
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(copy[i], 0);
  }
}

TEST(ArrayTest, deepCopyArrayAssign)
{
  const int size = 5;
  Array<int> array(size);
  Array<int> copy = array;
  ASSERT_EQ(array.size(), size);
  for (int i = 0; i < size; ++i) {
    array[i] = i;
  }
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(array[i], i);
  }

  // checking if copy array isn't modified
  for (int i = 0; i < size; ++i) {
    ASSERT_EQ(copy[i], 0);
  }
}
