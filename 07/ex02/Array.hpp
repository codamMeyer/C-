#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>
#include <iostream>

template<class T>
class Array
{
public:
  Array()
    : _size(0)
    , _elements(new T[0]()){};

  Array(unsigned int n)
    : _size(n)
    , _elements(new T[n]()){};

  Array(const Array& other)
    : _size(other._size)
  {
    this->_elements = new T[_size]();
    for (unsigned int i = 0; i < _size; ++i) {
      this->_elements[i] = other._elements[i];
    }
  };

  ~Array() { delete[] _elements; };

  Array& operator=(const Array& other)
  {
    this->_size = other._size;
    this->_elements = new T[_size]();
    for (unsigned int i = 0; i < _size; ++i) {
      this->_elements[i] = other._elements[i];
    }
    return *this;
  };

  T& operator[](unsigned int i)
  {
    if (i >= _size) {
      throw std::out_of_range("out of range");
    }
    return _elements[i];
  };

  const T& operator[](unsigned int i) const
  {
    if (i >= _size) {
      throw std::out_of_range("out of range");
    }
    return _elements[i];
  };

  int size() const { return this->_size; };

private:
  unsigned int _size;
  T* _elements;
};

#endif // ARRAY_H
