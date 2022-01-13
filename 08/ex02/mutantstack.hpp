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
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return this->c.begin(); };
  const_iterator begin() const { return this->c.begin(); };
  reverse_iterator rbegin() { return this->c.rbegin(); };
  const_reverse_iterator rbegin() const { return this->c.rbegin(); };
  iterator end() { return this->c.end(); };
  const_iterator end() const { return this->c.end(); };
  reverse_iterator rend() { return this->c.rend(); };
  const_reverse_iterator rend() const { return this->c.rend(); };
};

#endif // MUTANTSTACK_H
