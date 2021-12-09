#include "FragTrap.hpp"
#include "Color.hpp"
#include <iostream>

FragTrap::FragTrap()
  : ClapTrap("Anonymous",
	     defaultHitPoints,
	     defaultEnergyPoints,
	     defaultAttackDemage)
{
  std::cout << "FragTrap was created using default constructor\n";
}

FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name, defaultHitPoints, defaultEnergyPoints, defaultAttackDemage)
{
  std::cout << "FragTrap " << name << " was created\n";
}

FragTrap::FragTrap(const FragTrap& other)
  : ClapTrap(other)
{
  std::cout << "FragTrap " << name << " was created using copy constructor\n";
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap " << name << " was destructed\n";
}

void
FragTrap::attack(std::string const& target)
{
  std::cout << Color::attack << "🧨 " << name << " attack " << target
	    << ", causing " << attackDemage << " points of damage!\n"
	    << Color::neutral;
}

void
FragTrap::highFivesGuys()
{
  std::cout << Color::blue << "👋 Hey Guys!\n" << Color::neutral;
}
