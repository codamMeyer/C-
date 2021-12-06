#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void
Account::_displayTimestamp(void)
{
  const std::time_t ttime = std::time(0);
  const std::tm* local_time = std::localtime(&ttime);
  const int current_month = 1 + local_time->tm_mon;
  const int current_year = 1900 + local_time->tm_year;

  std::cout << "[";
  std::cout << current_year;
  if (current_month < 10)
    std::cout << "0";
  std::cout << current_month;
  std::cout << local_time->tm_mday;
  std::cout << "_" << local_time->tm_hour << 1 + local_time->tm_min
	    << 1 + local_time->tm_sec << "] ";
}

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts)
  , _amount(initial_deposit)
  , _nbDeposits(0)
  , _nbWithdrawals(0)
{
  ++_nbAccounts;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit
	    << ";created\n";
}

Account::~Account()
{
  --_nbAccounts;
  _totalAmount -= _amount;
  _totalNbDeposits -= _nbDeposits;
  _totalNbWithdrawals -= _nbWithdrawals;
  _displayTimestamp();
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
  _displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts()
	    << ";total:" << Account::getTotalAmount()
	    << ";deposits:" << Account::getNbDeposits()
	    << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void
Account::makeDeposit(int deposit)
{
  _displayTimestamp();
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
  _displayTimestamp();
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
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
	    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
	    << std::endl;
}
