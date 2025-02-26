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

void RPN::calcStacks() {
    std::cout << "TOP: " << _stacks.top() << std::endl;

    while (!_stacks.empty()) {
        std::string current = _stacks.top();
        _stacks.pop();

        if (current == "+" || current == "-" || current == "*" || current == "/") {
            processOperator(current);
        } else {
            // Push back operand for now or calculate when necessary
            std::cout << "Operand: " << current << std::endl;
        }
    }
}

void RPN::processOperator(const std::string& op) {
    if (_stacks.size() < 2) {
        throw std::runtime_error("Not enough operands for operation.");
    }

    std::string operand2 = _stacks.top();
    _stacks.pop();
    std::string operand1 = _stacks.top();
    _stacks.pop();

    double num1 =stringToDouble(operand1);
    double num2 =stringToDouble(operand2);
    double result = 0;

    if (op == "+") {
        result = num1 + num2;
    } else if (op == "-") {
        result = num1 - num2;
    } else if (op == "*") {
        result = num1 * num2;
    } else if (op == "/") {
        if (num2 == 0) {
            throw std::runtime_error("Division by zero.");
        }
        result = num1 / num2;
    }

    _stacks.push(doubleToString(result));
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

std::string RPN::doubleToString(double value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void RPN::splitStr(std::string s)
{    
    std::istringstream iss(s);
    std::string token;
    
    while (iss >> token) {
        std::cout << "Found token: " << token << std::endl;
    }
}
