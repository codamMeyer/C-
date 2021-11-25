#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <string>

class WeaponTest
{
public:
  WeaponTest()
    : weaponA("Bazuca")
  {}
  Weapon weaponA;
};

TEST_CASE_METHOD(WeaponTest, "Basic weapon")
{
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
    : weaponB("knife")
  {}
  Weapon weaponB;
};

TEST_CASE_METHOD(HumansTest, "HumanA")
{
  HumanA A = HumanA("Bob", weaponA);
  CHECK(A.getWaponType() == "Bazuca");
  A.attack();
  weaponA.setType("knife");
  CHECK(A.getWaponType() == "knife");
  A.attack();
}

TEST_CASE_METHOD(HumansTest, "HumanB")
{
  HumanB B = HumanB("Jim");
  CHECK(B.getWeapon() == NULL);
  B.attack();

  B.setWeapon(weaponB);
  CHECK(B.getWeapon()->getType() == "knife");
  B.attack();
  weaponB.setType("Bottle");
  CHECK(B.getWeapon()->getType() == "Bottle");
  B.attack();
}