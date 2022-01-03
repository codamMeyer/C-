#include "Bureaucrat.hpp"
#include <exception>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(Bureaucrat, gradeTooLowBureaucrat)
{
  EXPECT_THROW(Bureaucrat("Bill", 160), Bureaucrat::GradeTooLowException);
}

TEST(Bureaucrat, decrementBureaucrat)
{
  EXPECT_THROW(Bureaucrat("Bill", 150).decrementGrade(),
	       Bureaucrat::GradeTooLowException);
}

TEST(Bureaucrat, incrementBureaucrat)
{
  EXPECT_THROW(Bureaucrat("Bill", 1).incrementGrade(),
	       Bureaucrat::GradeTooHighException);
}

TEST(Bureaucrat, gradeTooHighBureaucrat)
{
  bool exceptionThrown = false;

  try {
    Bureaucrat bill("Bill", 0);
  } catch (std::exception& e) {
    exceptionThrown = true;
    std::cout << e.what() << std::endl;
  }
  ASSERT_TRUE(exceptionThrown);
}

TEST(Bureaucrat, validGradeBureaucrat)
{
  bool exceptionThrown = false;

  try {
    Bureaucrat bill("Bill", 50);
  } catch (std::exception& e) {
    exceptionThrown = true;
    std::cout << e.what() << std::endl;
  }
  ASSERT_FALSE(exceptionThrown);
}