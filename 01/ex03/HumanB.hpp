#ifndef HUMANB_H
#define HUMANB_H
#include "HumanA.hpp"
#include "Weapon.hpp"

class HumanB : public Human
{
public:
  HumanB(std::string name);
  void setWeapon(Weapon* weapon);
  void attack() const;
  Weapon* getWeapon();

private:
  Weapon* weapon;
};

#endif // HUMANB_H