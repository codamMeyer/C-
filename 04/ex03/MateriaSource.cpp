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
  for (int i = 0; i < maxMaterias; ++i) {
    if (other.knownMaterias[i] != NULL) {
      knownMaterias[i] = other.knownMaterias[i]->clone();
    }
  }
}

MateriaSource::~MateriaSource()
{
  std::cout << "MateriaSource Constructor called\n";
  for (int i = 0; i < maxMaterias; ++i) {
    if (knownMaterias[i] != NULL) {
      delete knownMaterias[i];
    }
  }
}

MateriaSource&
MateriaSource::operator=(const MateriaSource& other)
{
  this->curIdx = other.curIdx;
  this->maxMaterias = other.maxMaterias;
  for (int i = 0; i < maxMaterias; ++i) {
    if (knownMaterias[i] != NULL) {
      delete knownMaterias[i];
      knownMaterias[i] = NULL;
    }
  }
  for (int i = 0; i < maxMaterias; ++i) {
    if (other.knownMaterias[i] != NULL) {
      knownMaterias[i] = other.knownMaterias[i]->clone();
    }
  }
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
    if (knownMaterias[i]->getType().compare(type) == 0) {
      return knownMaterias[i]->clone();
    }
  }
  return NULL;
}
