#include "ClapTrap.hpp"
#include "Color.hpp"
#include <iostream>

ClapTrap::ClapTrap()
  : name("anonymous")
  , hitPoints(10)
  , energyPoints(10)
  , attackDemage(0)
  , demageColor(Color::red)
  , attackColor(Color::orange)
  , repairColor(Color::green)
  , neutralColor(Color::neutral)
{
  std::cout << "New ClapTrap was created using default constructor\n";
}

ClapTrap::ClapTrap(const std::string& name)
  : name(name)
  , hitPoints(10)
  , energyPoints(10)
  , attackDemage(0)
  , demageColor(Color::red)
  , attackColor(Color::orange)
  , repairColor(Color::green)
  , neutralColor(Color::neutral)
{
  std::cout << "ClapTrap " << name << " was created\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
  : name(other.name)
  , hitPoints(other.hitPoints)
  , energyPoints(other.energyPoints)
  , attackDemage(other.attackDemage)
  , demageColor(Color::red)
  , attackColor(Color::orange)
  , repairColor(Color::green)
  , neutralColor(Color::neutral)
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
  std::cout << attackColor << "🔫 ClapTrap " << name << " attack " << target
	    << ", causing " << attackDemage << " points of damage!\n"
	    << neutralColor;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << demageColor << name << ": Ouch! That hurts!\n";
  std::cout << "💔 ClapTrap " << name << " was attacked and received " << amount
	    << " points of damage!\n"
	    << neutralColor;
  hitPoints -= amount;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
  std::cout << repairColor << "💚 ClapTrap " << name
	    << " is being repaired with " << amount << " points\n"
	    << neutralColor;
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
