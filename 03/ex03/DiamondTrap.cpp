#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
  : ClapTrap("default_clap_name",
	     FragTrap::defaultHitPoints,
	     ScavTrap::defaultEnergyPoints,
	     FragTrap::defaultAttackDamage)
  , FragTrap("Default")
  , ScavTrap("Default")
  , name("Default")
{
  std::cout << "Default DiamondTrap was created\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name",
	     FragTrap::defaultHitPoints,
	     ScavTrap::defaultEnergyPoints,
	     FragTrap::defaultAttackDamage)
  , FragTrap(name)
  , ScavTrap(name)
  , name(name)
{
  std::cout << "DiamondTrap " << name << " was created\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
  : ClapTrap(other)
  , FragTrap(other)
  , ScavTrap(other)
{}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap " << name << " was destructed\n";
}

void
DiamondTrap::whoAmI(void)
{
  std::cout << "Who Am I ???\n"
	    << this->name << " - " << ClapTrap::name << std::endl;
}
