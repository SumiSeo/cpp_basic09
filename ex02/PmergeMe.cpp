#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
};


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

void PmergeMe::init_vector(int converted)
{
    this->_p.push_back(converted);
}

void PmergeMe::init_deque(int converted)
{
    this->_d.push_back(converted);
}


void PmergeMe::sort_vector(void)
{
    if(this->_size - 0 > 2)
    {}
    print_before("Vector");

    // 
    clock_t start, end;
    float time;
    start = clock();
    end = clock();
    time = static_cast<double>(end-start);
    
    
};

void PmergeMe::sort_deque(void)
{
    if(this->_size - 0 > 2)
    {}
    print_before("Deque");
    
};


void PmergeMe::print_before(std::string type)
{
    std::string s;
    std::stringstream ss; 
    for(std::vector<int>::const_iterator i = _p.begin(); i != _p.end(); i++)
    {      
        ss << *i;
        ss << " ";
        s = ss.str();
    }
    std::cout << type << "Before: " << s << std::endl;
};

void PmergeMe::print_after()
{

};

void PmergeMe::print_first_exec_time()
{

};

void PmergeMe::print_second_exec_time()
{

};

void PmergeMe::init_size(int i)
{
    this->_size = i;
}


PmergeMe::~PmergeMe()
{
    
};

