#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  ~FragTrap();

  void attack(std::string const& target);
  void highFivesGuys(void);

protected:
  static const int defaultHitPoints = 100;
  static const int defaultEnergyPoints = 100;
  static const int defaultAttackDamage = 30;
};

#endif // FRAGTRAP_H