#include "Converter.hpp"
#include <exception>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(ConverterToChar, nonDisplayableConvertion)
{
  EXPECT_THROW(Converter::toChar("0"), Converter::NonDisplayable);
}

TEST(ConverterToChar, impossibleConvertion)
{
  EXPECT_THROW(Converter::toChar("138"), Converter::ImpossibleConversion);
}

TEST(ConverterToChar, possibleConvertion)
{
  ASSERT_EQ('0', Converter::toChar("48"));
}
