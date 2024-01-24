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

static bool isHigherThanLastDate(std::string &lastDate, std::string &currDate)
{
    std::tm currTm = {};
    std::sscanf(currDate.c_str(), "%d-%d-%d", &currTm.tm_year, &currTm.tm_mon, &currTm.tm_mday);
    currTm.tm_year -= 1900;
    currTm.tm_mon--;

    std::tm lastTm = {};
    std::sscanf(lastDate.c_str(), "%d-%d-%d", &lastTm.tm_year, &lastTm.tm_mon, &lastTm.tm_mday);
    lastTm.tm_year -= 1900;
    lastTm.tm_mon--;

    if (currTm.tm_year != lastTm.tm_year)
        return currTm.tm_year > lastTm.tm_year;
    if (currTm.tm_mon != lastTm.tm_mon)
        return currTm.tm_mon > lastTm.tm_mon;
    return currTm.tm_mday > lastTm.tm_mday;
}

static double toDouble(std::string str)
{
    if (str[0] == '+' || str[0] == '-')
    {
        if (str[0] == '-')
            throw std::runtime_error("Error: not a positive number!");
        str.erase(0, 1);
    }
    char *checkptr;
    double result = strtod(str.c_str(), &checkptr);
    if (*checkptr)
        throw std::runtime_error("Error: not a valid number!");
    return result;
}

std::string getPreviousDate(std::string currDate)
{
    std::tm tm = {};
    std::sscanf(currDate.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;

    std::time_t time = std::mktime(&tm);
    time -= 86400;
    std::tm* newTm = std::localtime(&time);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", newTm);
    std::string previousDate(buffer);
    return previousDate;
}

int CheckDateFormat(std::string &date)
{
    std::tm tm = {};
    std::sscanf(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon--;
    std::cout << "\nYear: " << tm.tm_year << "\nMonth: " << tm.tm_mon << "\nDay: " << tm.tm_mday << std::endl;
    if (std::mktime(&tm) == -1)
        return 0;
    return (1);
}

int cleanValues(std::string & value1, std::string & value2)
{
    value1.erase(std::remove_if(value1.begin(), value1.end(), isspace), value1.end());
    value2.erase(std::remove_if(value2.begin(), value2.end(), isspace), value2.end());
    if (value1.empty() || value2.empty())
        return 0;
    return 1;
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
        if (!cleanValues(date, value))
        {
            std::cout << "Error: bad input => " << s.str() << std::endl;
            continue;
        }
        if (!CheckDateFormat(date))
        {
            std::cout << "Error: bad input => " << s.str() << std::endl;
            continue;
        }
        double doubleVal;
        try
        {
            doubleVal = toDouble(value);
            if (doubleVal > 1000)
                throw std::runtime_error("Eroor: too large a number");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            continue;
        }
        
        std::string lastDate = (--btcEx.end())->first;
        if (isHigherThanLastDate(lastDate, date))
            date = lastDate;
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
    try
    {
        BitcoinExchange btc;
        std::fstream fin;
        std::map<std::string, double>  btcEx;
        fin.open("data.csv", std::ios::in);

        std::string line;
        std::string date;
        std::string exchangeRate;
        std::string value;
        std::string tmp;

        std::getline(fin, line);
        std::stringstream s(line);
        if (line.empty() || !std::getline(s, date, ',') || !std::getline(s, exchangeRate, ','))
            throw (std::runtime_error("Wrong csv data format"));
        if (date != "date" || exchangeRate != "exchange_rate")
            throw (std::runtime_error("Wrong csv data titles!"));
        while (std::getline(fin, line) && !line.empty())
        {
            std::stringstream s(line);
            if (!std::getline(s, date, ',') || !std::getline(s, exchangeRate, ','))
                throw (std::runtime_error("Wrong data format!"));
            if (!cleanValues(date, exchangeRate))
                throw (std::runtime_error("Empty Values!"));
            if (!CheckDateFormat(date))
                throw (std::runtime_error("Invalid Date!"));
            double val = toDouble(exchangeRate);
            btcEx[date] = val;
        }
        if (btcEx.empty())
            throw (std::runtime_error("Database is empty!"));
        btc.mapExchange(btcEx);
        getCurrValue(btc, argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}