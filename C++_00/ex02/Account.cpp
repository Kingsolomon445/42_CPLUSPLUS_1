#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = getNbAccounts();
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" <<
    "amount:" << this->checkAmount() << ";" <<
    "created" << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = getNbAccounts();
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" <<
    "amount:" << this->checkAmount() << ";" <<
    "created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" <<
    "amount:" << this->checkAmount() << ";" <<
    "closed" << std::endl;
    _nbAccounts--;
}

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

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" <<
    "p_amount:" << this->checkAmount();
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";" <<
    "amount:" << this->checkAmount() << ";" << 
    "nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" <<
    "p_amount:" << this->checkAmount();
    if (this->_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";" << 
    "amount:" << this->checkAmount() << ";" <<
    "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}
int		Account::checkAmount( void ) const
{
    return this->_amount;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" <<
    "amount:" << this->checkAmount() << ";" <<
    "deposits:" << this->_nbDeposits << ";" <<
    "withdrawals:" << this->_nbWithdrawals << std::endl;
}

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
    std::cout << "accounts:" << getNbAccounts() << ";" <<
    "total:" << getTotalAmount() << ";" <<
    "deposits:" << getNbDeposits() << ";" <<
    "withdrawals:" << getNbWithdrawals() << std::endl;
}
