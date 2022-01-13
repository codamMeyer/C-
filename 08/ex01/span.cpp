#include "span.hpp"
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int n)
  : maxElements(n)

{}

Span::Span(const Span& other)
  : maxElements(other.maxElements)
  , elements(other.elements.begin(), other.elements.end())
{}

Span::~Span() {}

Span&
Span::operator=(const Span& other)
{
  maxElements = other.maxElements;
  elements = MySet(other.elements.begin(), other.elements.end());
  return *this;
}

void
Span::addNumber(int nbr)
{
  if (elements.size() < maxElements) {
    elements.insert(nbr);
  } else {
    throw std::out_of_range("out of range");
  }
}

int
Span::shortestSpan() const
{
  if (elements.size() <= 1) {
    throw std::out_of_range("Not enough elements");
  }

  int lhs = 0;
  int rhs = 0;
  int shortestSpan = std::numeric_limits<int>::max();
  for (iterator it = elements.begin(); it != --elements.end();) {
    lhs = *it;
    rhs = *(++it);
    shortestSpan = std::min(shortestSpan, rhs - lhs);
  }
  // std::cout << "Shortest span is the diff of " << lhs << " and " << rhs << ":
  // "
  //     << shortestSpan;

  return shortestSpan;
}

int
Span::longestSpan() const
{
  if (elements.size() <= 1) {
    throw std::out_of_range("Not enough elements");
  }
  const int first = *elements.begin();
  const int last = *(--elements.end());
  // std::cout << "Longest span is the diff of " << last << " and " << first
  //     << ": " << last - first;
  return last - first;
}

Span::Span()
  : maxElements(0)
{}
