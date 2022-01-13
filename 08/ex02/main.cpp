#include "mutantstack.hpp"
#include <assert.h>
#include <iostream>
#include <vector>
int
main()
{
  MutantStack<int> myStack;

  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(17);
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(737);
  vec.push_back(0);

  std::vector<int>::iterator v_it;

  for (v_it = vec.begin(); v_it != vec.end(); ++v_it) {
    MutantStack<int>::iterator s_ite = myStack.end();

    myStack.push(*v_it);
    std::cout << *s_ite << " == " << *v_it << '\n';
    assert(*(myStack.end() - 1) == *v_it);
  }

  MutantStack<int>::iterator it = myStack.begin();
  MutantStack<int>::iterator ite = myStack.end();
  ++it;
  --it;
  v_it = vec.begin();
  while (it != ite) {
    assert(*it == *v_it);
    std::cout << *it << " == " << *v_it << '\n';
    ++it;
    ++v_it;
  }
}
