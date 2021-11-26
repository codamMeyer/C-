#include "Karen.hpp"

Karen::Karen()
{
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
  switch (levelIndex) {
    case DEBUG:
      debug();
    case INFO:
      info();
    case WARNING:
      warning();
    case ERROR:
      error();
      break;
    default:
      invalid();
      break;
  }
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
  std::cout << "[" << stringLevels[DEBUG] << "]:\n"
	    << colorLevels[DEBUG]
	    << "I love to get extra bacon for my "
	       "7XL-double-cheese-triple-pickle-special-ketchup burger. I just "
	       "love it!\033[0m\n\n";
}

void
Karen::info(void)
{
  std::cout
    << "[" << stringLevels[INFO] << "]:\n"
    << colorLevels[INFO]
    << "I cannot believe adding extrabacon cost more money. You don’t "
       "put enough! If you did I would not have to askfor it!\033[0m\n\n";
}

void
Karen::warning(void)
{
  std::cout
    << "[" << stringLevels[WARNING] << "]:\n"
    << colorLevels[WARNING]
    << "I think I deserve to have some extra bacon for free. I’ve been coming "
       "here for years and you just started working here last "
       "month.\033[0m\n\n";
}

void
Karen::error(void)
{
  std::cout
    << "[" << stringLevels[ERROR] << "]:\n"
    << colorLevels[ERROR]
    << "This is unacceptable, I want to speak to the manager now.\033[0m\n\n";
}

void
Karen::invalid(void)
{
  std::cout
    << "[ Probably complaining about insignificant problems ]\033[0m\n\n";
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