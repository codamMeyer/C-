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
  std::string name;
  int hitPoints;
  int energyPoints;
  int attackDemage;

  const std::string& demageColor;
  const std::string& attackColor;
  const std::string& repairColor;
  const std::string& neutralColor;
};

#endif // CLAPTRAP_H