#ifndef WHATEVER_H
#define WHATEVER_H

template<typename T>
void
swap(T& lhs, T& rhs)
{
  T temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template<typename T>
T
min(const T& lhs, const T& rhs)
{
  if (lhs < rhs) {
    return lhs;
  }
  return rhs;
}

template<typename T>
T
max(const T& lhs, const T& rhs)
{
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

#endif // WHATEVER_H
