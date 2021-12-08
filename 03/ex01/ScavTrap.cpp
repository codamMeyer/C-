#include "ScavTrap.hpp"
#include "Color.hpp"
#include <iostream>

ScavTrap::ScavTrap()
  : ClapTrap("Anonymous",
	     defaultHitPoints,
	     defaultEnergyPoints,
	     defaultAttackDemage)
{
  std::cout << "New ScavTrap was created using default constructor\n";
}

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap("Anonymous",
	     defaultHitPoints,
	     defaultEnergyPoints,
	     defaultAttackDemage)
{
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
ScavTrap::guardGate()
{
  std::cout << Color::gateKeeper << "🔒 " << name
	    << " Has entered gate keeper mode\n"
	    << Color::neutral;
}
