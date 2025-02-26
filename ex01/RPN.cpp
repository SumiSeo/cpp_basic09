#include "RPN.hpp"


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

void RPN::addStack(std::string arg)
{
    _stacks.push(arg);
}