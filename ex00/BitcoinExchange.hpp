#ifndef BITCOINEXCHANGE__HPP
#define BITCOINEXCHANGE__HPP

#include <list>
#include <iostream>
#include <fstream>

class BitcoinExchange 
{
    private:
        std::string filename;
        static float rate;
    public :
        BitcoinExchange();
        BitcoinExchange(std::string name);
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange &operator=(const BitcoinExchange &original);
        ~BitcoinExchange();
};

#endif