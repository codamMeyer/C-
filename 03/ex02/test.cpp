#include "FragTrap.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(FragTrap, Costructors)
{
  FragTrap A("Mike");
  FragTrap B("Buddy");
  FragTrap C("Jake");

  C = B;
  EXPECT_TRUE(A.getAttackDamage() == B.getAttackDamage());
  EXPECT_TRUE(A.getAttackDamage() == C.getAttackDamage());
  EXPECT_TRUE(A.getEnergyPoints() == B.getEnergyPoints());
  EXPECT_TRUE(A.getEnergyPoints() == C.getEnergyPoints());
  EXPECT_TRUE(A.getHitPoints() == B.getHitPoints());
  EXPECT_TRUE(A.getHitPoints() == C.getHitPoints());
  EXPECT_TRUE(B.getName() == C.getName());
}

TEST(FragTrap, attack)
{
  FragTrap B("Buddy");
  B.attack("Monster");
}

TEST(FragTrap, takeDamageAndRepair)
{
  FragTrap B("Buddy");
  const int amout = 2;
  const int expected = B.getHitPoints() - amout;
  B.attack("Monster");
  B.takeDamage(amout);
  EXPECT_EQ(B.getHitPoints(), expected);
  B.beRepaired(amout);
  EXPECT_EQ(B.getHitPoints(), expected + amout);
}