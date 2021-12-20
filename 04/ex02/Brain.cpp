#include "Brain.hpp"
#include <sstream>

Brain::Brain()
  : nextIdea(0)
{
  std::stringstream idea;

  for (int i = 0; i < maxIdeas; ++i) {
    idea << "Stupid idea number " << i;
    ideas[i] = idea.str();
    idea.str("");
  }
}

Brain::Brain(const Brain& other)
  : nextIdea(other.nextIdea)
{
  for (int i = 0; i < maxIdeas; ++i) {
    ideas[i] = other.ideas[i];
  }
}

Brain::~Brain() {}

Brain&
Brain::operator=(const Brain& other)
{
  nextIdea = other.nextIdea;
  for (int i = 0; i < maxIdeas; ++i) {
    ideas[i] = other.ideas[i];
  }
  return *this;
}

const std::string&
Brain::getNextIdea()
{
  const int cur = nextIdea;
  nextIdea = (nextIdea + 1) % maxIdeas;
  return ideas[cur];
}