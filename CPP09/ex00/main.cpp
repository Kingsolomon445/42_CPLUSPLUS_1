#include "BitcoinExchange.hpp"
#include <limits>

static bool isLowerThanFirstDate(std::string &firstDate, std::string &currDate)
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

static double toDouble(std::string str)
{
    if (str[0] == '+' || str[0] == '-')
    {
        if (str[0] == '-')
            throw std::runtime_error("Error: not a positive number.");
        str.erase(0, 1);
    }
    char *checkptr;
    double result = strtod(str.c_str(), &checkptr);
    if (*checkptr)
        throw std::runtime_error("Error: not a valid number.");
    if (result > 1000)
        throw std::runtime_error("Error: too large a number.");
    return result;
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
    std::map<std::string, double> btcEx;

    finArg.open(fName, std::ios::in);
    btcEx = btc.getBtcEx();
    std::getline(finArg, line);
    while (std::getline(finArg, line) && !line.empty())
    {
        std::stringstream s(line);
        if (!std::getline(s, date, '|') || !std::getline(s, value, '|'))
        {
            std::cout << "Error: bad input => " << s.str() << std::endl;
            continue;
        }
        date.erase(std::remove_if(date.begin(), date.end(), isspace), date.end());
        value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());
        if (date.empty() || value.empty())
        {
            std::cout << "Error: bad input => " << s.str() << std::endl;
            continue;
        }
        double doubleVal;
        try
        {
            doubleVal = toDouble(value);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        
        std::string firstDate = btcEx.begin()->first;
        std::map<std::string, double>::iterator it = btcEx.find(date);
        while (it == btcEx.end() && !isLowerThanFirstDate(firstDate, date))
        {
            date = getPreviousDate(date);
            it = btcEx.find(date);
        }
        if (it != btcEx.end())
            std::cout << date << " => " << value << " = " << doubleVal * it->second << std::endl; 
        else
            std::cout << "Date: " << date << " or earlier doesn't exist!" << std::endl;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    std::fstream fin;
    std::map<std::string, double>  btcEx;
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