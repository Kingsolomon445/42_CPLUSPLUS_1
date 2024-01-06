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
        std::map<std::string, float> _btcEx;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & other);
        BitcoinExchange & operator=(const BitcoinExchange & other);

        void mapExchange(std::map<std::string, float> & btcEx);
        std::map<std::string, float> &getBtcEx();
} ;

#endif