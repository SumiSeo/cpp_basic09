#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

};

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
    rate = 0.3;
    std::cout << "default constrcutor with name" << std::endl;
    std::string str;
    std::string fileContents;
    while (std::getline(file, str))
    {
        std::cout << "STR : " << str << std::endl;
        std::stringstream ss(str); 
        std::string key;
        while(std::getline(ss, key,'|'))
        {   
            std::cout << "KEY : "<< key << std::endl;
        }
        // fileContents += str;
        // fileContents.push_back('\n');

    }  


};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
    if(this != &original)
    {
        this->rate = original.rate;
    }
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if(this != &original)
    {
        this->rate = original.rate;
    }
    return *this;
};

BitcoinExchange::~BitcoinExchange()
{
    //default destructor
};

void BitcoinExchange::formatContents(std::string file)
{
    std::cout << "fielContents: " << file << std::endl;
};
