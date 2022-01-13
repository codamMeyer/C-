#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
  typedef std::stack<T> BaseClass;
  typedef typename BaseClass::container_type Container;
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;

  iterator begin() { return this->c.begin(); };
  const_iterator begin() const { return this->c.begin(); };
  iterator rbegin() { return this->c.rbegin(); };
  iterator end() { return this->c.end(); };
  const_iterator end() const { return this->c.end(); };
  iterator rend() { return this->c.rend(); };
};

#endif // MUTANTSTACK_H