#ifndef BITCOINEXCHANGE__HPP
#define BITCOINEXCHANGE__HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <time.h>


class BitcoinExchange 
{
    private :
        std::list<std::pair<std::string, std::string> > contents;      void formatContents(std::string name);
        std::string findDB(time_t validInputTime);
    public :
        BitcoinExchange();
        BitcoinExchange(std::ifstream& file);
        BitcoinExchange(const BitcoinExchange &original);
        BitcoinExchange &operator=(const BitcoinExchange &original);
        ~BitcoinExchange();
};

#endif