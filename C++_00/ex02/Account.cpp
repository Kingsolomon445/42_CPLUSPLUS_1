#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

// STATIC MEMBER VAR DEFINITIONS
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//CONSTRUCTORS
Account::Account() : _accountIndex (_nbAccounts), _amount(0), _nbDeposits(0), 
_nbWithdrawals(0)
{
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" <<
    "amount:" << _amount << ";" <<
    "created" << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex (_nbAccounts), _amount(initial_deposit), _nbDeposits(0), 
_nbWithdrawals(0)
{
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" <<
    "amount:" << _amount << ";" <<
    "created" << std::endl;
}

//DESTRUCTOR
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" <<
    "amount:" << _amount << ";" <<
    "closed" << std::endl;
    _nbAccounts--;
}

// STATIC ACCESSORS
int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}


// MEMBER FUNCTIONS
void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" <<
    "p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";" <<
    "amount:" << _amount << ";" << 
    "nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" <<
    "p_amount:" << _amount;
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";" << 
    "amount:" << _amount << ";" <<
    "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}
int		Account::checkAmount( void ) const
{
    return _amount;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" <<
    "amount:" << _amount << ";" <<
    "deposits:" << _nbDeposits << ";" <<
    "withdrawals:" << _nbWithdrawals << std::endl;
}


// STATIC METHODS
void    Account::_displayTimestamp(void)
{
    time_t  now;
    char buffer[20];

    now = time(0);
    
    tm *lctm = localtime(&now);
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", lctm);
    std::cout << buffer << " ";
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" <<
    "total:" << _totalAmount << ";" <<
    "deposits:" << _totalNbDeposits << ";" <<
    "withdrawals:" << _totalNbWithdrawals << std::endl;
}
