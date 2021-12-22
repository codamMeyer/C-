#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

class MateriaTest : public ::testing::Test
{
public:
  MateriaTest() { materia = NULL; }
  ~MateriaTest() { delete materia; }
  AMateria* materia;
};

TEST_F(MateriaTest, createIce)
{
  materia = new Ice();
  EXPECT_STREQ(materia->getType().data(), "ice");
}

TEST_F(MateriaTest, createCure)
{
  materia = new Cure();
  EXPECT_STREQ(materia->getType().data(), "cure");
}

TEST_F(MateriaTest, characterEmptyInventory)
{
  Character james("James");
  Character mike("Mike");
  james.use(0, mike);
}

TEST_F(MateriaTest, characterUseInvalidInventoryIndex)
{
  Character james("James");
  Character mike("Mike");
  james.use(-1, mike);
  james.use(4, mike);
}

TEST(InventoryTest, characterEquipeFiveItens)
{
  AMateria* extra = new Ice();

  Character james("James");
  Character mike("Mike");
  int i = 0;
  james.equip(new Ice());
  james.equip(new Cure());
  james.equip(new Ice());
  james.equip(new Cure());
  james.equip(extra);

  EXPECT_STREQ(james.getName().data(), "James");
  james.use(0, mike);
  james.use(1, mike);
  james.use(2, mike);
  james.use(3, mike);
  delete extra;
}

TEST(InventoryTest, characterTest)
{
  Character james("James");
  Character mike("Mike");
  james.equip(new Ice());
  EXPECT_STREQ(james.getName().data(), "James");
  james.use(0, mike);
}

TEST(InventoryTest, copyCharacter)
{
  Character* james = new Character("James");
  Character mike("Mike");

  std::cout << "\n\n equip mike:\n";
  mike.equip(new Cure());
  mike.equip(new Ice());
  EXPECT_STREQ(mike.getName().data(), "Mike");

  std::cout << "\n\n equip james:\n";

  james->equip(new Ice());
  std::cout << "\n\n Copy james:\n";
  james->equip(new Cure());
  james->equip(new Ice());
  james->equip(new Cure());
  mike = *james;

  EXPECT_STREQ(james->getName().data(), "James");
  EXPECT_STREQ(mike.getName().data(), "James");
  std::cout << "\n\n Destroy\n";

  delete james;
}

TEST(InventoryTest, MateriaSourceCreateUnkownMateria)
{
  IMateriaSource* src = new MateriaSource();

  AMateria* tmp = src->createMateria("ice");
  EXPECT_EQ(tmp, (AMateria*)NULL);

  delete src;
}

TEST(InventoryTest, MateriaSourceCreatekownMateria)
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  AMateria* tmp = src->createMateria("cure");
  EXPECT_EQ(tmp->getType(), "cure");
  delete tmp;
  tmp = src->createMateria("ice");
  EXPECT_EQ(tmp->getType(), "ice");

  delete tmp;
  delete src;
}

TEST(InventoryTest, MateriaSourceLearnMoreThanCapacity)
{
  IMateriaSource* src = new MateriaSource();
  ICharacter* me = new Character("me");
  AMateria* tmp;

  for (int i = 0; i < 4; ++i) {
    src->learnMateria(new Cure());
    tmp = src->createMateria("cure");
    me->equip(tmp);
  }
  AMateria* extra = new Ice();
  src->learnMateria(extra);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  for (int i = 0; i < 4; ++i) {
    me->use(i, *me);
  }
  delete src;
  delete me;
  delete extra;
}
