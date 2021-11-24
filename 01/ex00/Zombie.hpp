#include <iostream>

class Zombie
{
public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void setName(std::string name);
  void announce(void) const;

private:
  std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);