#include "Account.hpp"
#include <iostream>
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts)
  , _amount(initial_deposit)
  , _nbDeposits(0)
  , _nbWithdrawals(0)
{
  ++_nbAccounts;
  _totalAmount += initial_deposit;
  std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit
	    << ";created\n";
}

Account::~Account()
{
  --_nbAccounts;
  _totalAmount -= _amount;
  _totalNbDeposits -= _nbDeposits;
  _totalNbWithdrawals -= _nbWithdrawals;
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
	    << ";closed\n";
}

int
Account::getNbAccounts()
{
  return _nbAccounts;
}

int
Account::getTotalAmount()
{
  return _totalAmount;
}

int
Account::getNbDeposits()
{
  return _totalNbDeposits;
}

int
Account::getNbWithdrawals()
{
  return _totalNbWithdrawals;
}

void
Account::displayAccountsInfos(void)
{
  std::cout << "accounts:" << Account::getNbAccounts()
	    << ";total:" << Account::getTotalAmount()
	    << ";deposits:" << Account::getNbDeposits()
	    << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void
Account::makeDeposit(int deposit)
{
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  ++Account::_totalNbDeposits;
  Account::_totalAmount += deposit;
  _amount += deposit;
  ++_nbDeposits;
  std::cout << ";deposit:" << deposit << ";amount:" << _amount
	      << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool
Account::makeWithdrawal(int withdrawal)
{
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  if (withdrawal <= _amount) {
    _amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    ++Account::_totalNbWithdrawals;
    ++_nbWithdrawals;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
	      << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
  }
  std::cout << ";withdrawal:refused\n";
  return false;
}

int
Account::checkAmount() const
{
  return _amount;
}

void
Account::displayStatus(void) const
{
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
	    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
	    << std::endl;
}
