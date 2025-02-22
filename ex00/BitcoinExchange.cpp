#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

};

BitcoinExchange::BitcoinExchange(std::string name)
{
    this->filename = name;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
    if(this != &original)
        this->filename = original.filename;
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if(this != &original)
        this->filename = original.filename;
    return *this;
};

BitcoinExchange::~BitcoinExchange()
{
    //default destructor
};
