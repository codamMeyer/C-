#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <ostream>
#include <string>

class WrongAnimal
{
public:
  WrongAnimal();
  WrongAnimal(std::ostream& os);
  WrongAnimal(const WrongAnimal& other);
  ~WrongAnimal();

  WrongAnimal& operator=(const WrongAnimal& other);
  void makeSound() const;
  const std::string& getType() const;

protected:
  std::string type;
  std::ostream& os;
};

#endif // WRONGANIMAL_H
