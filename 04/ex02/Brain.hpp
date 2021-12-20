#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain
{
public:
  Brain();
  Brain(const Brain& other);
  virtual ~Brain();

  Brain& operator=(const Brain& other);

  const std::string& getNextIdea();

private:
  int nextIdea;
  static const int maxIdeas = 100;
  std::string ideas[maxIdeas];
};

#endif // BRAIN_H