#include "PmergeMe.hpp"
#include <sstream>
#include <string>

/*
Your program must be able to handle at
least 3000 different integers.
*/

/*
implement your algori"thm for each container
./PmergeMe 3 5 9 7 4 
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
*/

int isValidInput(std::string s)
{

    std::cout << s << std::endl;
    return 0;
}
int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    try
    {     
        // std::istringstream iss(argv);
        // isValidInput(argv);
        // positive integer sequence  (Ford-Johnson algorithm.)
        // std::string input = argv[1];
        // std::cout << input << std::endl;
        std::cout << "here" << std::endl;
        (void)argv;
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}
