#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <string>

class ClapTrap
{
public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ~ClapTrap();

  ClapTrap& operator=(const ClapTrap& other);

  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void setDebugMode(bool mode);
  void setName(const std::string& name);
  const std::string& getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDemage() const;

private:
  static const int defaultHitPoints = 10;
  static const int defaultEnergyPoints = 10;
  static const int defaultAttackDemage = 0;

  std::string name;
  int hitPoints;
  int energyPoints;
  int attackDemage;
};

std::ostream& operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif // CLAPTRAP_H