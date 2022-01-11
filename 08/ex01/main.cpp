#include "span.hpp"
#include <assert.h>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

void
getShortestAndLongestSpan(const Span& sp)
{
  try {
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest:  " << sp.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}


int
main()
{
  Span sp = Span(5);

  getShortestAndLongestSpan(sp);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  getShortestAndLongestSpan(sp);

  try {
    sp.addNumber(19);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}
