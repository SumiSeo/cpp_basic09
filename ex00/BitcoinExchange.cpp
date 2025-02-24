#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

};

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
    std::cout << "default constrcutor with name" << std::endl;
    std::string str;
    std::string fileContents;
    while (std::getline(file, str))
    {   
        std::string delimiter = "|";
        std::string key = str.substr(0, str.find(delimiter));
        std::string value = str.substr(key.length());
        contents.push_back(std::pair<std::string, std::string>(key, value));
        // while(std::getline(ss, key,'|'))
        // {
        //     std::cout << "KEY : "<< key << std::endl;
        // }
        // fileContents += str;
        // fileContents.push_back('\n');
    }

    for (std::list<std::pair<std::string,std::string> >::iterator it = contents.begin(); it != contents.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
    if (this != &original)
    {
    }
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
    if (this != &original)
    {
    }
    return *this;
};

BitcoinExchange::~BitcoinExchange() {
    // default destructor
};

void BitcoinExchange::formatContents(std::string file)
{
    std::cout << "fielContents: " << file << std::endl;
};
