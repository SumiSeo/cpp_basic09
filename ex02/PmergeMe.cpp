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

void PmergeMe::insertion_sort_deque(int left, int right) 
{
    for (int i = left + 1; i <= right; i++) {
        int key = _d[i];
        int j = i - 1;
        while (j >= left && _d[j] > key) {
            _d[j + 1] = _d[j];
            j--;
        }
        _d[j + 1] = key;
    }
}


void PmergeMe::merge_sort_deque(int left, int mid, int right) 
{
    std::vector<int> left_part(_d.begin() + left, _d.begin() + mid + 1);
    std::vector<int> right_part(_d.begin() + mid + 1, _d.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while ((size_t)i < left_part.size() && (size_t)j < right_part.size()) 
    {
        if (left_part[i] <= right_part[j]) 
            _d[k++] = left_part[i++];
        else 
            _d[k++] = right_part[j++];
    }

    while ((size_t)i < left_part.size()) 
        _d[k++] = left_part[i++];

    while ((size_t)j < right_part.size()) 
        _d[k++] = right_part[j++];
}


void PmergeMe::insertion_sort(int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = _p[i];
        int j = i - 1;
        while (j >= left && _p[j] > key) {
            _p[j + 1] = _p[j];
            j--;
        }
        _p[j + 1] = key;
    }
}


void PmergeMe::merge_sort(int left, int mid, int right) 
{
    std::vector<int> left_part(_p.begin() + left, _p.begin() + mid + 1);
    std::vector<int> right_part(_p.begin() + mid + 1, _p.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while ((size_t)i < left_part.size() && (size_t)j < right_part.size()) 
    {
        if (left_part[i] <= right_part[j]) 
            _p[k++] = left_part[i++];
        else 
            _p[k++] = right_part[j++];
    }

    while ((size_t)i < left_part.size()) 
        _p[k++] = left_part[i++];

    while ((size_t)j < right_part.size()) 
        _p[k++] = right_part[j++];
}

void PmergeMe::merge_insertion_sort_vector(int left, int right, int size) 
{
    if (left >= right)
        return;

    if (right - left + 1 <= size) 
    {
        insertion_sort(left, right);
        return;
    }

    int mid = (left + right) / 2;
    merge_insertion_sort_vector(left, mid, size);
    merge_insertion_sort_vector(mid + 1, right, size);
    merge_sort(left, mid, right);
}

void PmergeMe::merge_insertion_sort_deque(int left, int right, int size) 
{
    if (left >= right)
        return;

    if (right - left + 1 <= size) 
    {
        insertion_sort_deque(left, right);
        return;
    }

    int mid = (left + right) / 2;
    merge_insertion_sort_deque(left, mid, size);
    merge_insertion_sort_deque(mid + 1, right, size);
    merge_sort_deque(left, mid, right);
}

void PmergeMe::sort_vector() 
{
    clock_t start, end;
    print_before("Vector");
    start = clock();
    merge_insertion_sort_vector(0, _p.size() - 1, 5);
    end = clock();
    double exec_time = double(end-start) / CLOCKS_PER_SEC;
    print_after("Vector");
    std::cout << "Time to process a range of " << this->_size  << " elements with std::[..] : " << std::fixed  << exec_time  << std::setprecision(5) <<" us" << std::endl;
}


void PmergeMe::sort_deque(void)
{
    clock_t start, end;
    print_before_deque("Deque");
    start = clock();
    merge_insertion_sort_deque(0, _d.size() - 1, 5);
    end = clock();
    double exec_time = double(end-start) / CLOCKS_PER_SEC;
    print_after_deque("Deque");
    std::cout << "Time to process a range of " << this->_size  << " elements with std::[..] : " << std::fixed  << exec_time  << std::setprecision(5) <<" us" << std::endl;
    
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
    std::cout << type << " Before: " << s << std::endl;
};

void PmergeMe::print_after(std::string type)
{
    std::string s;
    std::stringstream ss; 
    for(std::vector<int>::const_iterator i = _p.begin(); i != _p.end(); i++)
    {      
        ss << *i;
        ss << " ";
        s = ss.str();
    }
    std::cout << type << " After: " << s << std::endl;
};


void PmergeMe::print_before_deque(std::string type)
{
    std::string s;
    std::stringstream ss; 
    for(std::deque<int>::const_iterator i = _d.begin(); i != _d.end(); i++)
    {      
        ss << *i;
        ss << " ";
        s = ss.str();
    }
    std::cout << type << " Before: " << s << std::endl;
};

void PmergeMe::print_after_deque(std::string type)
{
    std::string s;
    std::stringstream ss; 
    for(std::deque<int>::const_iterator i = _d.begin(); i != _d.end(); i++)
    {      
        ss << *i;
        ss << " ";
        s = ss.str();
    }
    std::cout << type << " After: " << s << std::endl;
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

