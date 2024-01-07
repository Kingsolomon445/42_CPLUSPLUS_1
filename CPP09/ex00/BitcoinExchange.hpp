#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <ctime>
#include <iomanip>


class BitcoinExchange
{
    private:
        std::map<std::string, double> _btcEx;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange & operator=(const BitcoinExchange & other);

        void mapExchange(std::map<std::string, double> & btcEx);
        std::map<std::string, double> &getBtcEx();
} ;

#endif