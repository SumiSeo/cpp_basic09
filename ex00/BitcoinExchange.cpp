#include "BitcoinExchange.hpp"
#include <limits.h>

BitcoinExchange::BitcoinExchange() {

};

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
    std::string str;
    std::string delimiter = "|";

    while (std::getline(file, str))
    {   
        std::string key = str.substr(0, str.find(delimiter));
        std::string value = str.substr(key.length());
        std::string trimmed;
 

        if(value.empty())
        {
            key = "Error: bad input => " + key;
            value = "";
        }
        else 
        {
            int i ; 
            trimmed = value.substr(1);
            std::istringstream ( trimmed ) >> i;
            if (i < 0) 
            {
                key = "Error: not a positive number.";
                value = "";
            }
            else if (i > 1000)
            {
                key = "Error: too large a number.";
                value = "";
            }
            else if (i >= INT_MAX)
            {
                key = "Error: too large a number.";
                value = "";
            }
            else if (i <= INT_MIN)
            {
                key = "Error: too small a number.";
                value = "";
            }
        }
        contents.push_back(std::pair<std::string, std::string>(key, value));
    }

    time_t validInputTime ;

    for(std::list<std::pair<std::string, std::string> >::iterator it = contents.begin(); it != contents.end(); it++)
    {
        if(it->first != "date ")
        {
            struct tm inputTime = {};

            if (strptime(it->first.c_str(), "%Y-%m-%d", &inputTime) != NULL && it->first != "date" && !it->second.empty())
            {
                validInputTime = mktime(&inputTime);
                std::string rate = findDB(validInputTime);
                float rateFloat, secondFloat;
                std::stringstream(rate) >> rateFloat;
                std::string trimmed = it->second.substr(1);
                std::stringstream(trimmed) >> secondFloat;
                std::cout << it->first  << " => " << secondFloat<< " => "<< rateFloat  * secondFloat<< std::endl;
            } 
            else
                std::cout << it->first << std::endl;


        }
    }
   
}

std::string BitcoinExchange::findDB(time_t validInputTime)
{
    std::ifstream dbFile;
    dbFile.open("data.csv");
    if(!dbFile.is_open())  
        std::cout << "Can not open db" << std::endl;

    std::string str;
    std::string delimiter = ",";
    time_t validDBTime ;
    while(std::getline(dbFile, str))
    {
        std::string keyStart = str.substr(0, str.find(delimiter));
        std::string rate= str.substr(str.find(delimiter)+1);
        struct tm dbTime = {};
 
        if (strptime(keyStart.c_str(), "%Y-%m-%d", &dbTime) != NULL)
        {        
                validDBTime = mktime(&dbTime);
                if(validDBTime >= validInputTime)
                    return rate;
        }
    }
    return NULL;
}


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

