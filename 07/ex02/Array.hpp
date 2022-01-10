#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>

template<class T>
class Array
{
public:
  Array()
    : _size(0)
    , elements(new T[0]()){};
  Array(unsigned int n)
    : _size(n)
    , elements(new T[n]()){};
  Array(const Array& other)
    : _size(other._size)
  {
    this->elements = new T[_size]();
    for (unsigned int i = 0; i < _size; ++i) {
      this->elements[i] = other.elements[i];
    }
  };
  ~Array() { delete[] elements; };
  Array& operator=(const Array& other)
  {
    this->_size = other._size;
    this->elements = new T[_size]();
    for (unsigned int i = 0; i < _size; ++i) {
      this->elements[i] = other.elements[i];
    }
    return *this;
  };
  T& operator[](unsigned int i)
  {
    if (i >= _size) {
      throw std::out_of_range("out of range");
    }
    return elements[i];
  };
  const T& operator[](unsigned int i) const
  {
    if (i >= _size) {
      throw std::out_of_range("out of range");
    }
    return elements[i];
  };

  int size() const { return this->_size; };

private:
  unsigned int _size;
  T* elements;
};

#endif // ARRAY_H
