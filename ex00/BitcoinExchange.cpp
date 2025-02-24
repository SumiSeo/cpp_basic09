#include "BitcoinExchange.hpp"

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

        if(value.empty())
        {
            key = "Error: bad input => " + key;
            value = "";
        }
        
        else if (value == "| -1")
        {
            key = "Error: not a positive number";
            value = "";
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
                std::stringstream(it->second) >> secondFloat;
                
                std::cout << it->first  << " => " << rateFloat  * secondFloat<< std::endl;
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

void BitcoinExchange::isValidFormat(std::string key, std::string rate)
{
    time_t validInputTime ;


    for(std::list<std::pair<std::string, std::string> >::iterator it = contents.begin(); it != contents.end(); it++)
    {
        struct tm inputTime = {};

        if (strptime(key.c_str(), "%Y-%m-%d", &inputTime) != NULL && it->first != "date" && !it->second.empty())
        {
                validInputTime = mktime(&inputTime);
                findDB(validInputTime);
        }
      
    }
    (void)rate;
    // std::cout << "rate " <<rate << std::endl;
    // struct tm tmKey = {};
    // if (strptime(key.c_str(), "%Y-%m-%d", &tmKey) != NULL)
    // {
     
    //     time_t dbTime = mktime(&tmKey);
    //     (void)dbTime;
    //     std::cerr << "valid date format!" << dbTime << std::endl;
    //     if(dbTime <= validInputTime)
    //         std::cout << "check" << std::endl;
    // }
    
    
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

