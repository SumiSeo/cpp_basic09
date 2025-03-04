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

double stringToDouble(const std::string& str)
 {
    double result;
    std::stringstream ss(str);
    ss >> result;
    if (ss.fail()) {
        throw std::runtime_error("Invalid number format.");
    }
    return result;
}

int isValidInput(int converted)
{
    if(converted  > 0 )
        return 1;
    else 
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
        PmergeMe m;
        int i = 1;
        while(argv[i])
        {
            int converted = stringToDouble(argv[i]);
            if(!isValidInput(converted))
                throw std::runtime_error("Error");
            else
            {
                m.init_vector(converted); 
                m.init_deque(converted); 
            }
            i++;
        
        }
        m.init_size(i - 1);
        m.sort_vector();
        // m.sort_deque();

    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}
