#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
public:
  Weapon();
  Weapon(std::string weaponType);
  const std::string& getType() const;
  void setType(std::string newType);

private:
  std::string type;
};

#endif // WEAPON_H