#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character()
  : ICharacter()
  , name("Annonymous")
  , maxItens(4)
  , curIdx(0)
{
  std::cout << "Character Default Constructor called\n";
  for (int i = 0; i < maxItens; ++i) {
    inventory[i] = NULL;
  }
}

Character::Character(const std::string& name)
  : ICharacter()
  , name(name)
  , maxItens(4)
  , curIdx(0)
{
  std::cout << "Character user-defined constructor called\n";
  for (int i = 0; i < maxItens; ++i) {
    inventory[i] = NULL;
  }
}

Character::Character(const Character& other)
  : ICharacter()
  , name(other.name)
  , maxItens(other.maxItens)
  , curIdx(other.curIdx)
{
  std::cout << "Character Copy Constructor called\n";

  deleteInventory();
  cloneInventory(other);
}

Character::~Character()
{
  std::cout << "Character Destructor called\n";

  deleteInventory();
}

Character&
Character::operator=(const Character& other)
{
  std::cout << "Assigment operator called\n";
  name = other.name;
  maxItens = other.maxItens;
  curIdx = other.curIdx;
  deleteInventory();
  cloneInventory(other);
  return *this;
}

void
Character::deleteInventory()
{
  for (int i = 0; i < maxItens; ++i) {
    if (inventory[i] != NULL) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
}

void
Character::cloneInventory(const Character& other)
{
  for (int i = 0; i < maxItens; ++i) {
    if (other.inventory[i]) {
      inventory[i] = other.inventory[i]->clone();
    }
  }
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
