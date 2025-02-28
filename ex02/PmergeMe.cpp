#include "PmergeMe.hpp"



PmergeMe::PmergeMe(int n)
{
    this->_size = n;
};


PmergeMe::PmergeMe(const PmergeMe &original)
{
    if(this != &original)
    {
        this->_size = original._size;
    }
};

PmergeMe &PmergeMe::operator=(const PmergeMe &original)
{
    if(this != &original)
    {
        this->_size = original._size;
    }
    return *this;
};


PmergeMe::~PmergeMe()
{
    
};

