#ifndef PMERGEME__HPP
#define PMERGEME__HPP

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
#include <deque>
#include <stdexcept>
#include <iomanip>

class PmergeMe
{
    private :
        int _size;
        std::vector<int> _p;
        std::deque<int> _d;

    public :
        PmergeMe();
        PmergeMe(int n);
        PmergeMe(const PmergeMe &original);
        PmergeMe &operator=(const PmergeMe &original);
        void init_size(int i);
        void init_vector(int converted);
        void init_deque(int converted);
        void sort_vector(void);
        void sort_deque(void);
        void print_before(std::string type);
        void print_after(std::string type);
        void print_second_exec_time();
        void merge_insertion_sort_vector(int left, int right, int size);
        void insertion_sort(int left, int right);
        void merge_sort(int left, int mid, int right);

        ~PmergeMe();
};


#endif