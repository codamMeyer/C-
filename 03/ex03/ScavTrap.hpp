#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);
  ~ScavTrap();

  void attack(std::string const& target);
  void guardGate(void);

private:
  static const int defaultHitPoints = 100;
  static const int defaultEnergyPoints = 50;
  static const int defaultAttackDemage = 20;
};

#endif // SCAVTRAP_H