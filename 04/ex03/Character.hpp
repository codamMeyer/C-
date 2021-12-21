#ifndef CHARACTER_H
#define CHARACTER_H
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
  Character(const std::string& name);
  Character(const Character& other);
  ~Character();

  Character& operator=(const Character& other);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

private:
  std::string name;
  const int maxItens;
  int curIdx;
  AMateria* inventory[4];
};

#endif // CHARACTER_H