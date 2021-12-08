#include "ClapTrap.hpp"
#include "Color.hpp"
#include <iostream>

ClapTrap::ClapTrap()
  : name("anonymous")
  , hitPoints(defaultHitPoints)
  , energyPoints(defaultEnergyPoints)
  , attackDemage(defaultAttackDemage)
{
  std::cout << "ClapTrap was created using default constructor\n";
}

ClapTrap::ClapTrap(const std::string& name)
  : name(name)
  , hitPoints(defaultHitPoints)
  , energyPoints(defaultEnergyPoints)
  , attackDemage(defaultAttackDemage)
{
  std::cout << "ClapTrap " << name << " was created\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
  : name(other.name)
  , hitPoints(other.hitPoints)
  , energyPoints(other.energyPoints)
  , attackDemage(other.attackDemage)
{
  std::cout << "ClapTrap " << name << " was created using copy constructor\n";
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap " << name << " was destructed\n";
}

ClapTrap&
ClapTrap::operator=(const ClapTrap& other)
{
  name = other.name;
  hitPoints = other.hitPoints;
  energyPoints = other.energyPoints;
  attackDemage = other.attackDemage;
  return *this;
}

void
ClapTrap::attack(std::string const& target)
{
  std::cout << Color::attack << "🔫 " << name << " attack " << target
	    << ", causing " << attackDemage << " points of damage!\n"
	    << Color::neutral;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << Color::demage << name << ": Ouch! That hurts!\n";
  std::cout << "💔 " << name << " was attacked and received " << amount
	    << " points of damage!\n"
	    << Color::neutral;
  hitPoints -= amount;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
  std::cout << Color::repair << "💚 " << name << " is being repaired with "
	    << amount << " points\n"
	    << Color::neutral;
  hitPoints += amount;
}

void
ClapTrap::setName(const std::string& name)
{
  this->name = name;
}

const std::string&
ClapTrap::getName() const
{
  return name;
}

int
ClapTrap::getHitPoints() const
{
  return hitPoints;
}

int
ClapTrap::getEnergyPoints() const
{
  return energyPoints;
}

int
ClapTrap::getAttackDemage() const
{
  return attackDemage;
}

std::ostream&
operator<<(std::ostream& os, const ClapTrap& clapTrap)
{
  os << "\nName: " << clapTrap.getName() << std::endl;
  os << "Attack Demage: " << clapTrap.getAttackDemage() << std::endl;
  os << "Energy Points: " << clapTrap.getEnergyPoints() << std::endl;
  os << "Hit Points: " << clapTrap.getHitPoints() << std::endl << std::endl;
  return os;
}
