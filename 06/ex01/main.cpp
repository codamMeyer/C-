#include "Data.hpp"
#include "Serializer.hpp"
#include <assert.h>
#include <iostream>
int
main()
{
  Data a(5, "Monique");
  uintptr_t rawData = serialize(&a);
  Data* b = deserialize(rawData);

  assert(&a == b);
  assert(a.id == b->id);
  assert(a.name == b->name);

  std::cout << "a address: " << &a << "\na id: " << a.id
	    << "\na name: " << a.name << std::endl;
  std::cout << "b address: " << b << "\nb id: " << b->id
	    << "\nb name: " << b->name << std::endl;
}