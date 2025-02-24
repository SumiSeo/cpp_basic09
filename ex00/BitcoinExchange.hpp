#ifndef BITCOINEXCHANGE__HPP
#define BITCOINEXCHANGE__HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>


class BitcoinExchange 
{
    private:
        std::list<std::pair<std::string, std::string> > contents;      void formatContents(std::string name);
    public :
        BitcoinExchange();
        BitcoinExchange(std::ifstream& file);
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange &operator=(const BitcoinExchange &original);
        ~BitcoinExchange();
};

#endif