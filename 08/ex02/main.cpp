#include "mutantstack.hpp"
#include <assert.h>
#include <iostream>
#include <list>

int
main()
{
  typedef MutantStack<int> MyStack;
  typedef std::list<int> Container;

  Container container;
  container.push_back(5);
  container.push_back(17);
  container.push_back(3);
  container.push_back(5);
  container.push_back(737);
  container.push_back(0);

  MyStack myStack;
  for (Container::iterator it = container.begin(); it != container.end();
       ++it) {
    myStack.push(*it);
  }

  MyStack::iterator it_stack = myStack.begin();

  std::cout << "\nForward Iterator:\n\n";
  for (Container::iterator it_container = container.begin();
       it_container != container.end() && it_stack != myStack.end();
       ++it_container, ++it_stack) {
    assert(*it_stack == *it_container);
    std::cout << "stack " << *it_stack << " == "
	      << "container " << *it_container << "\n";
  }
  std::cout << "\nReverse Iterator:\n\n";
  MyStack::reverse_iterator rit_stack = myStack.rbegin();
  for (Container::reverse_iterator rit_container = container.rbegin();
       rit_container != container.rend() && rit_stack != myStack.rend();
       ++rit_container, ++rit_stack) {
    assert(*rit_stack == *rit_container);
    std::cout << "stack " << *rit_stack << " == "
	      << "container " << *rit_container << "\n";
  }

  std::cout << "\nStack Operations:\n\n";
  std::cout << "Stack size: " << myStack.size() << '\n';
  std::cout << "Stack top: " << myStack.top() << '\n';
  std::cout << "Poping element\n";
  myStack.pop();
  std::cout << "Stack top: " << myStack.top() << '\n';
}
