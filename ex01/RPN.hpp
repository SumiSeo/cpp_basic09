#ifndef RPN__HPP
#define RPN__HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

class RPN 
{
    private :
        std::stack<std::string> _stacks;
        static const char* _operations[4];

    public : 
        RPN();
        RPN(const RPN &original);
        int addStack(std::string arg);
        int strToInt(std::string s);
        RPN &operator=(const RPN &original);
        bool isValidInt(const std::string &s);
        void printStackInfo();
        ~RPN();
 

};


#endif