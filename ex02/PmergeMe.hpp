#ifndef PMERGEME__HPP
#define PMERGEME__HPP

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

class PmergeMe
{
    private :
        int _size;

    public :
        PmergeMe();
        PmergeMe(int n);
        PmergeMe(const PmergeMe &original);
        PmergeMe &operator=(const PmergeMe &original);
        ~PmergeMe();
};


#endif