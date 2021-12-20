#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
  Cat();
  Cat(std::ostream& os);
  Cat(const Cat& other);
  ~Cat();

  Cat& operator=(const Cat& other);

  const std::string& think() const;
  virtual void makeSound() const;

private:
  Brain* brain;
};

#endif // CAT_H