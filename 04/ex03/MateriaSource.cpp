#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
  : IMateriaSource()
  , maxMaterias(4)
  , curIdx(0)
{
  std::cout << "MateriaSource Constructor called\n";
  for (int i = 0; i < maxMaterias; ++i) {
    knownMaterias[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& other)
  : IMateriaSource()
  , maxMaterias(other.maxMaterias)
  , curIdx(other.curIdx)
{
  std::cout << "MateriaSource Constructor called\n";
  deleteMaterias();
  cloneKnownMaterias(other);
}

MateriaSource::~MateriaSource()
{
  std::cout << "MateriaSource Constructor called\n";
  deleteMaterias();
}

MateriaSource&
MateriaSource::operator=(const MateriaSource& other)
{
  this->curIdx = other.curIdx;
  this->maxMaterias = other.maxMaterias;
  deleteMaterias();
  cloneKnownMaterias(other);
  return *this;
}

void
MateriaSource::learnMateria(AMateria* m)
{
  if (curIdx < maxMaterias) {
    knownMaterias[curIdx] = m;
    ++curIdx;
  }
}

AMateria*
MateriaSource::createMateria(std::string const& type)
{
  for (int i = 0; i < curIdx; ++i) {
    if (knownMaterias[i]->getType() == type) {
      return knownMaterias[i]->clone();
    }
  }
  return NULL;
}

void
MateriaSource::deleteMaterias()
{
  for (int i = 0; i < maxMaterias; ++i) {
    if (knownMaterias[i] != NULL) {
      delete knownMaterias[i];
      knownMaterias[i] = NULL;
    }
  }
}

void
MateriaSource::cloneKnownMaterias(const MateriaSource& other)
{
  for (int i = 0; i < maxMaterias; ++i) {
    if (other.knownMaterias[i] != NULL) {
      knownMaterias[i] = other.knownMaterias[i]->clone();
    }
  }
}
