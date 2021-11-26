#include "Karen.hpp"

Karen::Karen()
{
  populateFunctions(complainLevels);
  populateString(stringLevels);
  populateColors(colorLevels);
}

Karen::~Karen()
{
  std::cout << "\033[0m";
}

void
Karen::complain(std::string level)
{
  Level levelIndex = getComplainLevelIndex(level);
  ComplainFunction func = complainLevels[levelIndex];

  (this->*func)();
}

Karen::Level
Karen::getComplainLevelIndex(std::string levelString) const
{
  for (int i = DEBUG; i < INVALID; ++i) {
    if (levelString == stringLevels[(Level)i])
      return (Level)i;
  }
  return INVALID;
}

void
Karen::debug(void)
{
  std::cout << colorLevels[DEBUG]
	    << "I love to get extra baconfor my "
	       "7XL-double-cheese-triple-pickle-special-ketchup burger. I just "
	       "love it!\n";
}

void
Karen::info(void)
{
  std::cout << colorLevels[INFO]
	    << "I cannot believe adding extrabacon cost more money. You don’t "
	       "put enough! If you did I would not have to askfor it!\n";
}

void
Karen::warning(void)
{
  std::cout
    << colorLevels[WARNING]
    << "I think I deserve to have some extra bacon for free. I’ve beencoming "
       "here for years and you just started working here last month.\n";
}

void
Karen::error(void)
{
  std::cout << colorLevels[ERROR]
	    << "This is unacceptable, I want to speak to the manager now.\n";
}

void
Karen::invalid(void)
{
  std::cout << "Please enter a valid option: DEBUG, INFO, WARNING, ERROR\n";
}

void
Karen::populateFunctions(ComplainFunction complainLevels[])
{

  complainLevels[DEBUG] = &Karen::debug;
  complainLevels[INFO] = &Karen::info;
  complainLevels[WARNING] = &Karen::warning;
  complainLevels[ERROR] = &Karen::error;
  complainLevels[INVALID] = &Karen::invalid;
}

void
Karen::populateString(std::string stringLevels[])
{
  stringLevels[DEBUG] = "DEBUG";
  stringLevels[INFO] = "INFO";
  stringLevels[WARNING] = "WARNING";
  stringLevels[ERROR] = "ERROR";
}

void
Karen::populateColors(std::string colorLevels[])
{
  colorLevels[DEBUG] = "\033[32m";
  colorLevels[INFO] = "\033[36m";
  colorLevels[WARNING] = "\033[1m\033[34m";
  colorLevels[ERROR] = "\033[1m\033[31m";
}