#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
  : ClapTrap("anonymous_clap_name")
  , name("anonymous")
{
  DiamondTrap::hitPoints = FragTrap::hitPoints;
  DiamondTrap::energyPoints = ScavTrap::energyPoints;
  DiamondTrap::attackDemage = FragTrap::attackDemage;
}

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name")
  , FragTrap(name)
  , ScavTrap(name)
  , name(name)
{
  DiamondTrap::hitPoints = FragTrap::hitPoints;
  DiamondTrap::energyPoints = ScavTrap::energyPoints;
  DiamondTrap::attackDemage = FragTrap::attackDemage;
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
  std::cout << "Who Am I ???\n" << this->name << std::endl;
  std::cout << ClapTrap::name << std::endl;
}
