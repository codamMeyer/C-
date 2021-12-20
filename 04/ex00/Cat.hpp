#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"

class Cat : public Animal
{
public:
  Cat();
  Cat(std::ostream& os);
  Cat(const Cat& other);
  ~Cat();

  virtual void makeSound() const;
};

#endif // CAT_H