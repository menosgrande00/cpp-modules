#include "BitcoinExchange.hpp"
#include <sstream>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& dbFilename)
{
    std::ifstream file(dbFilename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open database file: " << dbFilename << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        
        if (commaPos == std::string::npos)
        {
            continue; 
        }

        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);

        double rate = std::atof(rateStr.c_str());

        _database[date] = rate;
    }

    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[2] = 29;
    }

    if (day > daysInMonth[month])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
    char* endPtr;
    value = std::strtod(valueStr.c_str(), &endPtr);

    if (valueStr.empty() || (*endPtr != '\0' && *endPtr != 'f')) {
        std::cerr << "Error: not a number." << std::endl;
        return false;
    }

    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000.0) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::processInput(const std::string& inputFilename) {
    std::ifstream file(inputFilename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t delimPos = line.find(" | ");
        if (delimPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delimPos);
        std::string valueStr = line.substr(delimPos + 3);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        if (!isValidValue(valueStr, value)) {
            continue;
        }

        std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
        
        if (it == _database.end() || it->first != date) {
            if (it == _database.begin()) {
                std::cerr << "Error: date is too early." << std::endl;
                continue;
            }
            --it;
        }

        double result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}