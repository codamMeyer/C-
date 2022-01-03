#include "Bureaucrat.hpp"
#include "Form.hpp"
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

TEST(Form, WronggradeForm)
{
  EXPECT_THROW(Form("Silly Form", 160, 5), Form::GradeTooLowException);
  EXPECT_THROW(Form("Silly Form", 60, 0), Form::GradeTooHighException);
}

TEST(Bureaucrat, notAbleToSign)
{
  Bureaucrat bill("Bill", 40);
  Form sillyForm("Silly Form", 15, 5);

  try {
    sillyForm.beSigned(bill);
  } catch (std::exception& e) {
    ASSERT_FALSE(sillyForm.getSignedBoolStatus());
  }
}

TEST(Bureaucrat, AbleToSign)
{
  Bureaucrat bill("Bill", 2);
  Form sillyForm("Silly Form", 15, 5);

  sillyForm.beSigned(bill);
  ASSERT_TRUE(sillyForm.getSignedBoolStatus());
}
