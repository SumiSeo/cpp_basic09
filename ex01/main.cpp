#include "RPN.hpp"

// RPN
// reverse polish notation 
// simply postfix notation
// (3+5) * (4+2)
// 3 5 + 4 2 + *
// using stack
// put stack 3 and then 5 and then add operand +
// take two numbers and do operate
// 8
// and then put 4 and 2 -> operatnd +
// 6
// 8 and 6 with operand * 
// 48

// maximumn argmuments are 10
// + = / * 
// error outputs should be cerr 
// one container : as a stack

/*
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
*/


int main(int argc, char **argv)
{
    if(argc < 4)
    {
        std::cerr << "Please put correct operations and numbers. Something is missing..."<< std::endl;
        return 0;

    }
    else
    {
        argv++;   
        RPN r;
        int i = 0 ;
        while(argv[i] != NULL)
        {
            r.addStack(argv[i]);
            std::cout << "argv[i] : " << argv[i] << std::endl;
            i++;
        }
    }
    
    return 0;

}