#ifndef RPN__HPP
#define RPN__HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

class RPN 
{
    private :
        std::stack<int> _stacks;
        std::stack<std::string> _splitted;
        static const char* _operations[4];

    public : 
        RPN();
        RPN(const RPN &original);
        RPN &operator=(const RPN &original);
        bool isValidInt(const std::string &s);
        void printStackInfo();
        void processOperator(std::string token);
        double stringToDouble(const std::string& str);
        int splitStr(std::string s);
        ~RPN();
 

};


#endif