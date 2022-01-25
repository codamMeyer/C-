#ifndef AMATERIA_H
#define AMATERIA_H
#include "ICharacter.hpp"
#include <string>

class AMateria
{
public:
  AMateria(std::string const& type);
  virtual ~AMateria();

  AMateria& operator=(const AMateria& other);
  AMateria(const AMateria& other);

  std::string const& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

protected:
  std::string type;
};

#endif // AMATERIA_H