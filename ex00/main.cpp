#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    else if (argc == 2)
    {
        std::string fName = argv[1];
        std::ifstream file;
        file.open(fName.c_str());
        if(file.is_open())
        {
            BitcoinExchange bte(file);
        }
        else
            std::cout << "Can not open the file : " << fName << std::endl;


    }
    
};