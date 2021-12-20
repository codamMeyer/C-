#ifndef ANIMAL_H
#define ANIMAL_H

#include <ostream>
#include <string>

class Animal
{
public:
  Animal();
  Animal(std::ostream& os);
  Animal(const Animal& other);
  virtual ~Animal();

  Animal& operator=(const Animal& other);
  virtual void makeSound() const = 0;
  virtual void think() const = 0;
  const std::string& getType() const;

protected:
  std::string type;
  std::ostream& os;
};

#endif // ANIMAL_H
