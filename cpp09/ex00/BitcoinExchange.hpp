#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;

        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr, double& value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& dbFilename);
        void processInput(const std::string& inputFilename);
};

#endif