#include "Converter.hpp"
#include <cmath>
#include <exception>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

/////////////////// CHAR
TEST(ConverterToChar, nonDisplayableConvertion)
{
  EXPECT_THROW(std::cout << static_cast<char>(Converter("0")),
	       Converter::NonDisplayableConversionExepction);
}

TEST(ConverterToChar, impossibleConvertionPos)
{
  EXPECT_THROW(std::cout << static_cast<char>(Converter("138")),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToChar, impossibleConvertionNeg)
{
  EXPECT_THROW(std::cout << static_cast<char>(Converter("-138")),
	       Converter::ImpossibleConversionExepction);
}


TEST(ConverterToChar, impossibleConvertionInf)
{
  EXPECT_THROW(std::cout << static_cast<char>(Converter("-inf")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<char>(Converter("+inf")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<char>(Converter("inf")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<char>(Converter("-inff")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<char>(Converter("+inff")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<char>(Converter("inff")),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToChar, impossibleConvertionNan)
{
  EXPECT_THROW(std::cout << static_cast<char>(Converter("nan")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<char>(Converter("nanf")),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToChar, possibleConvertion)
{
  EXPECT_EQ(static_cast<char>(Converter("48")), '0');
}

TEST(ConverterToChar, convertCharLiteral)
{
  EXPECT_EQ(static_cast<char>(Converter("a")), 'a');
}


/////////////////// INT

TEST(ConverterToInt, impossibleConvertionPos)
{
  EXPECT_THROW(std::cout << static_cast<int>(Converter("23456789876543456789")),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToInt, impossibleConvertionNeg)
{
  EXPECT_THROW(
    std::cout << static_cast<int>(Converter("-3456789865432345678976543")),
    Converter::ImpossibleConversionExepction);
}

TEST(ConverterToInt, impossibleConvertionInf)
{
  EXPECT_THROW(std::cout << static_cast<int>(Converter("-inf")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<int>(Converter("+inf")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<int>(Converter("inf")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<int>(Converter("-inff")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<int>(Converter("+inff")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<int>(Converter("inff")),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToInt, impossibleConvertionNan)
{
  EXPECT_THROW(std::cout << static_cast<int>(Converter("nan")),
	       Converter::ImpossibleConversionExepction);
  EXPECT_THROW(std::cout << static_cast<int>(Converter("nanf")),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToInt, possibleConvertion)
{
  EXPECT_EQ(static_cast<int>(Converter("48")), 48);
  EXPECT_EQ(static_cast<int>(Converter("-48")), -48);
}

/////////////////// FLOAT
TEST(ConverterToFloat, impossibleConvertionPos)
{
  std::string input = std::to_string(std::numeric_limits<double>::max());
  EXPECT_THROW(std::cout << static_cast<float>(Converter(input)),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToFloat, impossibleConvertionNeg)
{
  std::string input = std::to_string(std::numeric_limits<double>::lowest());
  EXPECT_THROW(std::cout << static_cast<float>(Converter(input)),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToFloat, possibleConvertionInf)
{
  EXPECT_EQ(static_cast<float>(Converter("-inf")),
	    -std::numeric_limits<float>::infinity());
  EXPECT_EQ(static_cast<float>(Converter("+inf")),
	    std::numeric_limits<float>::infinity());
  EXPECT_EQ(static_cast<float>(Converter("inf")),
	    std::numeric_limits<float>::infinity());
  EXPECT_EQ(static_cast<float>(Converter("-inff")),
	    -std::numeric_limits<float>::infinity());
  EXPECT_EQ(static_cast<float>(Converter("+inff")),
	    std::numeric_limits<float>::infinity());
  EXPECT_EQ(static_cast<float>(Converter("inff")),
	    std::numeric_limits<float>::infinity());
}

TEST(ConverterToFloat, possibleConvertionNan)
{
  EXPECT_TRUE(std::isnan(static_cast<float>(Converter("nan"))));
  EXPECT_TRUE(std::isnan(static_cast<float>(Converter("nanf"))));
}

TEST(ConverterToFloat, possibleConvertion)
{
  EXPECT_FLOAT_EQ(static_cast<float>(Converter("48.2")), 48.2);
  EXPECT_FLOAT_EQ(static_cast<float>(Converter("-48.2")), -48.2);
}

/////////////////// DOUBLE
TEST(ConverterToDouble, impossibleConvertionPos)
{
  std::string input = std::to_string(std::numeric_limits<double>::max());
  EXPECT_THROW(std::cout << static_cast<double>(Converter(input)),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToDouble, impossibleConvertionNeg)
{
  std::string input = std::to_string(std::numeric_limits<double>::lowest());
  EXPECT_THROW(std::cout << static_cast<double>(Converter(input)),
	       Converter::ImpossibleConversionExepction);
}

TEST(ConverterToDouble, possibleConvertionInf)
{
  EXPECT_EQ(static_cast<double>(Converter("-inf")),
	    -std::numeric_limits<double>::infinity());
  EXPECT_EQ(static_cast<double>(Converter("+inf")),
	    std::numeric_limits<double>::infinity());
  EXPECT_EQ(static_cast<double>(Converter("inf")),
	    std::numeric_limits<double>::infinity());
  EXPECT_EQ(static_cast<double>(Converter("-inff")),
	    -std::numeric_limits<double>::infinity());
  EXPECT_EQ(static_cast<double>(Converter("+inff")),
	    std::numeric_limits<double>::infinity());
  EXPECT_EQ(static_cast<double>(Converter("inff")),
	    std::numeric_limits<double>::infinity());
}

TEST(ConverterToDouble, possibleConvertionNan)
{
  EXPECT_TRUE(std::isnan(static_cast<double>(Converter("nan"))));
  EXPECT_TRUE(std::isnan(static_cast<double>(Converter("nanf"))));
}

TEST(ConverterToDouble, possibleConvertion)
{
  EXPECT_DOUBLE_EQ(static_cast<double>(Converter("48.2")), 48.2);
  EXPECT_DOUBLE_EQ(static_cast<double>(Converter("-48.2")), -48.2);
}
