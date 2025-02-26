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
        std::stack<std::string> _stacks;
        std::stack<std::string> _splitted;
        static const char* _operations[4];

    public : 
        RPN();
        RPN(const RPN &original);
        int addStack(std::string arg);
        int strToInt(std::string s);
        RPN &operator=(const RPN &original);
        bool isValidInt(const std::string &s);
        void printStackInfo();
        void calcStacks();
        void processOperator(const std::string& op);
        double stringToDouble(const std::string& str);
        std::string doubleToString(double value);
        void splitStr(std::string s);

        ~RPN();
 

};


#endif