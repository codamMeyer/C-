#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(const std::string& name)
  : ICharacter()
  , name(name)
  , maxItens(4)
  , curIdx(0)
{
  std::cout << "Character Constructor called\n";
  for (int i = 0; i < maxItens; ++i) {
    inventory[i] = NULL;
  }
}

Character::Character(const Character& other)
  : ICharacter()
  , name(other.name)
  , maxItens(other.maxItens)
  , curIdx(0)
{
  for (int i = 0; i < maxItens; ++i) {
    if (other.inventory[i]) {
      inventory[i] = other.inventory[i]->clone();
    }
  }
}

Character::~Character()
{
  for (int i = 0; i < maxItens; ++i) {
    if (inventory[i]) {
      delete inventory[i];
    }
  }
}

Character&
Character::operator=(const Character& other)
{
  name = other.name;
  for (int i = 0; i < maxItens; ++i) {
    if (other.inventory[i]) {
      inventory[i] = other.inventory[i]->clone();
    }
  }
  return *this;
}
std::string const&
Character::getName() const
{
  return name;
}

void
Character::equip(AMateria* m)
{
  if (curIdx < maxItens) {
    inventory[curIdx] = m;
    ++curIdx;
  }
}

void
Character::unequip(int idx)
{
  if (idx >= 0 && idx < maxItens) {
    inventory[idx] = NULL;
  }
}

void
Character::use(int idx, ICharacter& target)
{
  if (curIdx > 0 && idx >= 0 && idx < maxItens) {
    inventory[idx]->use(target);
  }
}
