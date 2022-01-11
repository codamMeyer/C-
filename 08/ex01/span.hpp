#ifndef SPAN_H
#define SPAN_H
#include <set>
#include <stdexcept>

class Span
{
public:
  Span(unsigned int n);
  Span(const Span& other);
  ~Span();
  Span& operator=(const Span& other);

  void addNumber(int nbr);
  int shortestSpan() const;
  int longestSpan() const;

  template<typename Iterator>
  void addNumbers(Iterator begin, Iterator end)
  {
    for (Iterator it = begin; it != end; ++it) {
      addNumber(*it);
    }
  };

private:
  Span();
  typedef std::multiset<int> MySet;
  typedef MySet::iterator iterator;

  unsigned int maxElements;
  std::multiset<int> elements;
};

#endif // SPAN_H
