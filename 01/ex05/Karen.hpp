#ifndef KAREN_H
#define KAREN_H
#include <iostream>

class Karen
{
public:
  typedef enum e_level
  {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID
  } Level;
  Karen();
  ~Karen();
  void complain(std::string level);
  Level getComplainLevelIndex(std::string levelString) const;

private:
  typedef void (Karen::*ComplainFunction)(void);

  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void invalid(void);

  void populateFunctions(ComplainFunction complainLevels[]);
  void populateString(std::string stringLevels[]);
  void populateColors(std::string colorLevels[]);

  ComplainFunction complainLevels[5];
  std::string stringLevels[4];
  std::string colorLevels[4];
};

#endif // KAREN_H