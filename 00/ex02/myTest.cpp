#include "Account.hpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class AccountTest
{
public:
  AccountTest()
    : ClientA(initial_deposit)
  {}
  const int initial_deposit = 100;
  Account ClientA;
};

TEST_CASE_METHOD(AccountTest, "getNbAccounts : One account")
{
  CHECK(Account::getNbAccounts() == 1);
}

TEST_CASE_METHOD(AccountTest, "getTotalAmount")
{
  CHECK(Account::getTotalAmount() == initial_deposit);
}

TEST_CASE_METHOD(AccountTest, "getNbDeposits")
{
  CHECK(Account::getNbDeposits() == 0);
}

TEST_CASE_METHOD(AccountTest, "getNbWithdrawals")
{
  CHECK(Account::getNbWithdrawals() == 0);
}

TEST_CASE_METHOD(AccountTest, "Make Deposit")
{
  REQUIRE(ClientA.checkAmount() == initial_deposit);
  ClientA.makeDeposit(200);
  CHECK(ClientA.checkAmount() == 300);
  CHECK(Account::getTotalAmount() == 300);
  CHECK(Account::getNbDeposits() == 1);
}

TEST_CASE_METHOD(AccountTest, "Withdraw More than available")
{
  REQUIRE(ClientA.checkAmount() == initial_deposit);
  REQUIRE(Account::getNbWithdrawals() == 0);
  CHECK_FALSE(ClientA.makeWithdrawal(300));
  CHECK(ClientA.checkAmount() == initial_deposit);
  CHECK(Account::getNbWithdrawals() == 0);
}

TEST_CASE_METHOD(AccountTest, "Withdraw valid amount")
{
  REQUIRE(ClientA.checkAmount() == initial_deposit);
  REQUIRE(Account::getNbWithdrawals() == 0);
  CHECK(ClientA.makeWithdrawal(50));
  CHECK(ClientA.checkAmount() == 50);
  CHECK(Account::getTotalAmount() == 50);
  CHECK(Account::getNbWithdrawals() == 1);
}

TEST_CASE_METHOD(AccountTest,
		 "Check amount after Client creation (initial deposit)")
{
  CHECK(ClientA.checkAmount() == initial_deposit);
}

class MultipleAccountTest : public AccountTest
{
public:
  MultipleAccountTest()
    : amounts{ 100, 200, 300 }
    , accounts(std::begin(amounts), std::end(amounts))
  {
  }
  int const amounts[3];
  std::vector<Account> accounts;
};

TEST_CASE_METHOD(MultipleAccountTest, "Check Number of Accounts")
{
  REQUIRE(Account::getNbAccounts() == 4);
  CHECK(Account::getTotalAmount() == 700);
}
