#include "ScavTrap.hpp"
#include "Color.hpp"
#include "FragTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
  : ClapTrap("Anonymous")
{
  hitPoints = defaultHitPoints;
  energyPoints = defaultEnergyPoints;
  attackDemage = defaultAttackDemage;
  std::cout << "ScavTrap was created using default constructor\n";
}

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap(name)
{
  hitPoints = defaultHitPoints;
  energyPoints = defaultEnergyPoints;
  attackDemage = defaultAttackDemage;
  std::cout << "ScavTrap " << name << " was created\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
  : ClapTrap(other)
{
  std::cout << "ScavTrap " << name << " was created using copy constructor\n";
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap " << name << " was destructed\n";
}

void
ScavTrap::attack(std::string const& target)
{
  std::cout << Color::attack << "🧨 " << name << " attack " << target
	    << ", causing " << attackDemage << " points of damage!\n"
	    << Color::neutral;
}

void
ScavTrap::guardGate(void)
{
  std::cout << Color::blue << "🔒 " << name << " Has entered gate keeper mode\n"
	    << Color::neutral;
}
