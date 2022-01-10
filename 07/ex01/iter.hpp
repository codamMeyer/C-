#ifndef ITER_H
#define ITER_H

template<typename T>
void
iter(const T* array, int size, void (*func)(const T&))
{
  for (int i = 0; i < size; ++i) {
    func(array[i]);
  }
}

template<typename T>
void
iter(T* array, int size, void (*func)(T&))
{
  for (int i = 0; i < size; ++i) {
    func(array[i]);
  }
}

#endif // ITER_H
