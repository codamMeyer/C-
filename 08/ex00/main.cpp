#include "easyfind.hpp"
#include <assert.h>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template<typename T>
void
printContainer(const T& container, const std::string& msg)
{
  std::cout << msg;
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int
main()
{
  std::vector<int> vec(5, 0);
  printContainer(vec, "Vector: ");
  assert(vec.end() == easyfind(vec, 1));
  vec.push_back(1); // insert at the end
  printContainer(vec, "Vector: ");
  assert(vec.end() != easyfind(vec, 1));

  std::list<int> l;
  assert(l.end() == easyfind(l, 1));
  l.push_back(3);
  l.push_back(3);
  l.push_back(3);
  printContainer(l, "List: ");
  assert(l.end() == easyfind(l, 1));
  l.push_back(1); // insert at the end
  printContainer(l, "List: ");
  assert(l.end() != easyfind(l, 1));
}
