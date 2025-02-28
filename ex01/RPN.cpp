#include "RPN.hpp"



const char* RPN::_operations[4] = {"+", "-", "*", "/"};

RPN::RPN()
{

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
    
    for (; i < s.size(); i++) 
        if (!isdigit(s[i])) return false;  
    return true;
}


void RPN::printStackInfo()
{
    std::cout << "STACK SIZE :" << _stacks.size() << std::endl;
    while (!_stacks.empty()) {
        std::cout << "TOP: " << _stacks.top() << std::endl;
        _stacks.pop();
    }
}

void  RPN::processOperator(std::string token) 
{
    if(isValidInt(token))
    {
        int num = stringToDouble(token);
        _stacks.push(num);
        return;
    }
    if (_stacks.size() < 2) 
        throw std::runtime_error("Error");

    int left = _stacks.top();
    _stacks.pop();
    int right = _stacks.top();
    _stacks.pop();
    if(token == "+")
    {
        int result = right + left;
        _stacks.push(result);
    }
    else if(token == "-")
    {
        int result = right - left;
        _stacks.push(result);
    }
    else if(token == "*")
    {
        int result = right * left;
        _stacks.push(result);
    }
    else if(token == "/")
    {
        if (left == 0)
            throw std::runtime_error("Error");
        int result = right / left;
        _stacks.push(result);
    }
    else
        throw std::runtime_error("Error");
    return;
}

double RPN::stringToDouble(const std::string& str) {
    double result;
    std::stringstream ss(str);
    ss >> result;
    if (ss.fail()) {
        throw std::runtime_error("Invalid number format.");
    }
    return result;
}



int RPN::splitStr(std::string s)
{    
    std::istringstream iss(s);
    std::string token;
    
    while (iss >> token) 
        processOperator(token);
    return  _stacks.top();
}
