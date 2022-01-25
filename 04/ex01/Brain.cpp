#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain()
  : nextIdea(0)
  , maxIdeas(100)
{
  std::stringstream idea;
  for (int i = 0; i < maxIdeas; ++i) {
    idea << "Stupid idea number " << i;
    ideas[i] = idea.str();
    idea.str("");
  }

  std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other)
  : nextIdea(other.nextIdea)
  , maxIdeas(other.maxIdeas)
{
  for (int i = 0; i < maxIdeas; ++i) {
    ideas[i] = other.ideas[i];
  }
  std::cout << "Brain copy constructor called\n";
}

Brain::~Brain()
{
  std::cout << "Brain destructor called\n";
}

Brain&
Brain::operator=(const Brain& other)
{
  nextIdea = other.nextIdea;
  maxIdeas = other.maxIdeas;
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