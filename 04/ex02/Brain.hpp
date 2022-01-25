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
  int maxIdeas;
  std::string ideas[100];
};

#endif // BRAIN_H
