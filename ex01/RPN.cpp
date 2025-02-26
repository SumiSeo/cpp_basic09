#include "RPN.hpp"



const char* RPN::_operations[4] = {"+", "-", "*", "/"};

RPN::RPN()
{
    std::cout << "default construtor called" << std::endl;

};

RPN::RPN(const RPN &original)
{
    if(this != &original)
    {
        
    }
};

RPN &RPN::operator=(const RPN &original)
{
    if(this != &original)
    {
       
    }
    return *this;
};

RPN::~RPN()
{

};

bool RPN::isValidInt(const std::string &s) {
    if (s.empty()) return false;
    
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-')
        return true;
    
    for (; i < s.size(); i++) 
    {
        if (!isdigit(s[i])) return false;  
      
    }
    return true;
}

int RPN::strToInt(std::string s)
{
    if(!isValidInt(s))  return -1;
    int converted;
    std::stringstream ss(s);
    if(s.empty())   return -1;
    ss >> converted;
    return converted;
}

int  RPN::addStack(std::string arg)
{
    int i = 0;

    while (i < 4)
    {
        if(arg == _operations[i])
        {
            std::cout <<" here" << std::endl;
            _stacks.push(arg);
            return 1;
        }
        i++;
    }
    
    int converted = strToInt(arg);
    if(converted != -1 )
    {
        _stacks.push(arg);       
        return 1; 
    }
    else
        return 0;
}
void RPN::printStackInfo()
{
    std::cout << "STACK SIZE :" << _stacks.size() << std::endl;
    while (!_stacks.empty()) {
        std::cout << "TOP: " << _stacks.top() << std::endl;
        _stacks.pop();
    }
}