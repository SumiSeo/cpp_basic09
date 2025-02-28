#include "RPN.hpp"

/*
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
*/

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Error"<< std::endl;
        return 0;

    }
        
    try
    {
        RPN r;
        int result = r.splitStr(argv[1]);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
   


    
    return 0;

}