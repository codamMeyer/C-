#include "ClapTrap.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(ClapTrap, Costructors)
{
  ClapTrap A;
  ClapTrap B("Buddy");
  ClapTrap C;

  C = B;
  EXPECT_TRUE(A.getAttackDemage() == B.getAttackDemage());
  EXPECT_TRUE(A.getAttackDemage() == C.getAttackDemage());
  EXPECT_TRUE(A.getEnergyPoints() == B.getEnergyPoints());
  EXPECT_TRUE(A.getEnergyPoints() == C.getEnergyPoints());
  EXPECT_TRUE(A.getHitPoints() == B.getHitPoints());
  EXPECT_TRUE(A.getHitPoints() == C.getHitPoints());
  EXPECT_TRUE(B.getName() == C.getName());
}

TEST(ClapTrap, attack)
{
  ClapTrap B("Buddy");
  B.attack("Monster");
}

TEST(ClapTrap, takeDemageAndRepair)
{
  ClapTrap B("Buddy");
  const int amout = 2;
  const int expected = B.getHitPoints() - amout;
  B.attack("Monster");
  B.takeDamage(amout);
  EXPECT_EQ(B.getHitPoints(), expected);
  B.beRepaired(amout);
  EXPECT_EQ(B.getHitPoints(), expected + amout);
}