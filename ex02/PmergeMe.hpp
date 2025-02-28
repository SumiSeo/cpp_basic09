#ifndef PMERGEME__HPP
#define PMERGEME__HPP

#include <iostream>
#include <vector>
#include <map>

class PmergeMe
{
    private :

    public :
        PmergeMe();
        PmergeMe(const PmergeMe &original);
        PmergeMe &operator=(const PmergeMe &original);
        ~PmergeMe();
};


#endif