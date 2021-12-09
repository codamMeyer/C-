#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& other);
  ~FragTrap();

  void attack(std::string const& target);
  void highFivesGuys(void);

private:
  static const int defaultHitPoints = 100;
  static const int defaultEnergyPoints = 100;
  static const int defaultAttackDemage = 30;
};

#endif // FRAGTRAP_H