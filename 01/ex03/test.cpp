#include "HumanA.hpp"
#include "HumanB.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <string>

class WeaponTest
{
public:
  WeaponTest()
    : weaponA()
  {}
  Weapon weaponA;
};

TEST_CASE_METHOD(WeaponTest, "Basic weapon")
{
  weaponA.setType("Bazuca");
  CHECK(weaponA.getType() == "Bazuca");
}

TEST_CASE_METHOD(WeaponTest, "Change weapon type")
{
  weaponA.setType("Bazuca");
  CHECK(weaponA.getType() == "Bazuca");
  weaponA.setType("knife");
  CHECK(weaponA.getType() == "knife");
}

class HumansTest : public WeaponTest
{
public:
  HumansTest()
  {
    weaponA.setType("Knife");
    weaponB.setType("Bazuca");
  }
  Weapon weaponB;
};

TEST_CASE_METHOD(HumansTest, "HumanA")
{
  HumanA A = HumanA("Bob", weaponA);
  CHECK(A.getWaponType() == "Knife");
  A.attack();
  weaponA.setType("Bottle");
  CHECK(A.getWaponType() == "Bottle");
  A.attack();
}

TEST_CASE_METHOD(HumansTest, "HumanB")
{
  HumanB B = HumanB("Jim");
  CHECK(B.getWeapon() == NULL);

  B.setWeapon(&weaponA);
  CHECK(B.getWeapon()->getType() == "Knife");
  B.attack();
  weaponA.setType("Bottle");
  CHECK(B.getWeapon()->getType() == "Bottle");
  B.attack();
}