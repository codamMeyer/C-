#include "mutantstack.hpp"
#include <gtest/gtest.h>
#include <iostream>

class MutantStackTest : public testing::Test
{
public:
  MutantStackTest()
    : myConstStack(myStack)
  {}
  MutantStack<int> myStack;
  const MutantStack<int>& myConstStack;
};

TEST_F(MutantStackTest, myStackBeginEndTest)
{
  myStack.push(1);
  myStack.push(3);
  ASSERT_EQ(*(myStack.begin()), 1);
  ASSERT_EQ(*(myStack.end() - 1), 3);
  ASSERT_EQ(myStack.top(), 3);
}

TEST_F(MutantStackTest, myConstStackBeginEndTest)
{
  myStack.push(1);
  myStack.push(3);
  ASSERT_EQ(*(myConstStack.begin()), 1);
  ASSERT_EQ(*(myConstStack.end() - 1), 3);
  ASSERT_EQ(myConstStack.top(), 3);
}

TEST_F(MutantStackTest, checkBeginAndEnd)
{
  myStack.push(1);
  EXPECT_EQ(*myStack.begin(), 1);

  myStack.push(2);
  EXPECT_EQ(*myStack.begin(), 1);

  myStack.push(3);
  EXPECT_EQ(*myStack.begin(), 1);

  EXPECT_EQ(*(myStack.end() - 1), 3);
}

TEST_F(MutantStackTest, checkEndAferPop)
{
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  EXPECT_EQ(*(myStack.end() - 1), 3);

  myStack.pop();
  EXPECT_EQ(*(myStack.end() - 1), 2);
}

TEST_F(MutantStackTest, moduleTest)
{
  std::vector<int> vec = { 5, 17, 3, 5, 737, 0 };
  std::vector<int>::iterator v_it;

  for (v_it = vec.begin(); v_it != vec.end(); ++v_it) {
    myStack.push(*v_it);
    EXPECT_EQ(*(myStack.end() - 1), *v_it);
  }

  MutantStack<int>::iterator it = myStack.begin();
  MutantStack<int>::iterator ite = myStack.end();
  ++it;
  --it;
  v_it = vec.begin();
  while (it != ite) {
    EXPECT_EQ(*it, *v_it);
    ++it;
    ++v_it;
  }
}