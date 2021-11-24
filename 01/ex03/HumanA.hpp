#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class Human
{
public:
    Human(std::string name);
protected:
    const std::string name;
};

class HumanA : public Human
{
public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
    const std::string& getWaponType() const;
private:
    Weapon& weapon;
};
#endif // HUMANA_H