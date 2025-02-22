#ifndef BITCOINEXCHANGE__HPP
#define BITCOINEXCHANGE__HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange 
{
    private:
        std::map<std::string, std::string> contents;
        float rate;
        void formatContents(std::string name);
    public :
        BitcoinExchange();
        BitcoinExchange(std::ifstream& file);
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange &operator=(const BitcoinExchange &original);
        ~BitcoinExchange();
};

#endif