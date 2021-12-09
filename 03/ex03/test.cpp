#include "DiamondTrap.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>

TEST(DiamondTrap, Costructors)
{
  DiamondTrap A("Bob");

  EXPECT_EQ(A.getHitPoints(), 100);
  EXPECT_EQ(A.getEnergyPoints(), 50);
  EXPECT_EQ(A.getAttackDamage(), 30);
}