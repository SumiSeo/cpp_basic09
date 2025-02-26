#ifndef RPN__HPP
#define RPN__HPP

#include <stack>
#include <iostream>

class RPN 
{
    private :
        std::stack<std::string> _stacks;

    public : 
        RPN();
        RPN(const RPN &original);
        void addStack(std::string arg);
        RPN &operator=(const RPN &original);
        ~RPN();
 

};


#endif