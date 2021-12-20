#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
  Dog();
  Dog(std::ostream& os);
  Dog(const Dog& other);
  ~Dog();

  Dog& operator=(const Dog& other);

  const std::string& think() const;
  virtual void makeSound() const;

private:
  Brain* brain;
};

#endif // DOG_H