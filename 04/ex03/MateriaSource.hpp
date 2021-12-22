#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  virtual ~MateriaSource();

  MateriaSource& operator=(const MateriaSource& other);

  virtual void learnMateria(AMateria*);
  virtual AMateria* createMateria(std::string const& type);

private:
  int maxMaterias;
  int curIdx;
  AMateria* knownMaterias[4];
};

#endif // MATERIASOURCE_H