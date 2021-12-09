#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap
  : public FragTrap
  , public ScavTrap
{
public:
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& other);
  ~DiamondTrap();

  using ScavTrap::attack;

  void whoAmI(void);

private:
  std::string name;
};

#endif // DIAMONDTRAP_H