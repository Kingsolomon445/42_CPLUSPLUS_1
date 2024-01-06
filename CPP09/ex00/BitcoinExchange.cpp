#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
{
    *this = other;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other)
{
    static_cast<void>(other);
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::mapExchange(std::map<std::string, float> & btcEx)
{
    _btcEx = btcEx;
}

std::map<std::string, float> &BitcoinExchange::getBtcEx()
{
    return _btcEx;
}