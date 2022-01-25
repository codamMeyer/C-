#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain
{
public:
  Brain();
  Brain(const Brain& other);
  Brain& operator=(const Brain& other);
  virtual ~Brain();
  const std::string& getNextIdea();

private:
  int nextIdea;
  int maxIdeas;
  std::string ideas[100];
};

#endif // BRAIN_H