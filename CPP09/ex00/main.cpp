#include "BitcoinExchange.hpp"
#include <limits>

bool isLowerThanFirstDate(std::string &firstDate, std::string &currDate)
{
    std::tm currTm = {};
    std::sscanf(currDate.c_str(), "%d-%d-%d", &currTm.tm_year, &currTm.tm_mon, &currTm.tm_mday);
    currTm.tm_year -= 1900;
    currTm.tm_mon--;

    std::tm firstTm = {};
    std::sscanf(firstDate.c_str(), "%d-%d-%d", &firstTm.tm_year, &firstTm.tm_mon, &firstTm.tm_mday);
    firstTm.tm_year -= 1900;
    firstTm.tm_mon--;

    if (currTm.tm_year != firstTm.tm_year)
        return currTm.tm_year < firstTm.tm_year;
    if (currTm.tm_mon != firstTm.tm_mon)
        return currTm.tm_mon < firstTm.tm_mon;
    return currTm.tm_mday < firstTm.tm_mday;
}

bool isValid(float number)
{
    if (number < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    if (number > std::numeric_limits<int>::max())
    {
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    return 1;
}

std::string getPreviousDate(std::string currDate)
{
    std::tm tm = {};
    std::sscanf(currDate.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon--;

    std::time_t time = std::mktime(&tm);
    time -= 86400;
    std::tm* newTm = std::localtime(&time);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", newTm);
    std::string previousDate(buffer);
    return previousDate;
}


void getCurrValue(BitcoinExchange & btc, const char *fName)
{
    std::string line;
    std::string date;
    std::string value;
    std::fstream finArg;
    std::map<std::string, float> btcEx;

    finArg.open(fName, std::ios::in);
    btcEx = btc.getBtcEx();
    while (std::getline(finArg, line) && !line.empty())
    {
        std::stringstream s(line);
        if (!std::getline(s, date, '|') || !std::getline(s, value, '|'))
        {
            std::cout << "Error: bad input." << std::endl;
            continue;
        }
        date.erase(std::remove_if(date.begin(), date.end(), isspace), date.end());
        value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());
        if (date.empty() || value.empty())
        {
            std::cout << "Error: bad input." << std::endl;
            continue;
        }
        std::stringstream ss;
        ss << value;
        float floatVal;
        ss >> floatVal;
        if (!isValid(floatVal))
            continue;
        std::string firstDate = btcEx.begin()->first;
        std::map<std::string, float>::iterator it = btcEx.find(date);
        while (it == btcEx.end() && !isLowerThanFirstDate(firstDate, date))
        {
            date = getPreviousDate(date);
            it = btcEx.find(date);
        }
        if (it != btcEx.end())
            std::cout << date << " => " << value << " = " << floatVal * it->second << std::endl; 
        else
            std::cout << "Date doesn't exist!";
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    BitcoinExchange btc;
    std::fstream fin;
    std::map<std::string, float>  btcEx;
    fin.open("data.csv", std::ios::in);

    std::string line;
    std::string date;
    std::string exchangeRate;
    std::string value;
    std::string tmp;
    while (std::getline(fin, line) && !line.empty())
    {
        std::stringstream s(line);
        std::getline(s, date, ',');
        std::getline(s, exchangeRate, ',');
        std::stringstream ss;
        ss << exchangeRate;
        ss >> btcEx[date];
    }
    btc.mapExchange(btcEx);
    getCurrValue(btc, argv[1]);
    return 0;
}