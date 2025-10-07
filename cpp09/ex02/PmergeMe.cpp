#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vec)
{
    fillVec(vec);
    // fillDeq(vec);
}


void checkDigit(std::string str)
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '\0')
        throw PmergeMe::InvalidArgumentException();
    if (str[i] == '+')
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            throw PmergeMe::InvalidArgumentException();
        i++;
    }
}

std::vector<int> convertStringsToIntegers(const std::vector<std::string>& args)
{
    std::vector<int> intVec;
    long num;
    for (size_t i = 0; i < args.size(); i++)
    {
        num = std::atol(args[i].c_str());
        if (num > INT_MAX || num < INT_MIN)
            throw PmergeMe::InvalidArgumentException();
        intVec.push_back(static_cast<int>(num));
    }
    return intVec;
}

std::vector<int> parseArgs(std::vector<std::string>& args)
{
    for (size_t i = 0; i < args.size(); i++)
        checkDigit(args[i]);
    return convertStringsToIntegers(args);
}

void PmergeMe::displayFirstline()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _Myvector.size(); i++)
    {
        std::cout << _Myvector[i] ;
        if (i != _Myvector.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::MergeInsertionSort()
{
    struct timeval tv;
    unsigned long startVec, endVec, startDeq, endDeq;
    displayFirstline();
    
    //Vector
    
    gettimeofday(&tv, NULL);
    startVec = tv.tv_sec * 1000000 + tv.tv_usec;

    MergeInsertionSortVec(_Myvector);
    
    gettimeofday(&tv, NULL);
    endVec = tv.tv_sec * 1000000 + tv.tv_usec;
    
    displayVec(_Myvector);
    displayTimeOfVec(endVec - startVec);
    
    //Deque
    
    gettimeofday(&tv, NULL);
    startDeq = tv.tv_sec * 1000000 + tv.tv_usec;
    
    MergeInsertionSortDeq(_Mydeque);
    
    gettimeofday(&tv, NULL);
    endDeq = tv.tv_sec * 1000000 + tv.tv_usec;
    displayTimeOfDeq(endDeq - startDeq);
}

// void PmergeMe::fillDeq(std::vector<int> vec)
// {
//     for (size_t i = 0; i < vec.size(); i++)
//         _Mydeque.push_back(vec[i]);
// }

//*** VECTOR METHODS ***/

void PmergeMe::fillVec(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        _Myvector.push_back(vec[i]);
}

bool rule(const Pair& a, const Pair& b)
{
    return a.second < b.second;
}

std::vector<Pair> PmergeMe::sortPairsVec(std::vector<int>& vec)
{
    std::vector<Pair> pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    std::sort(pairs.begin(), pairs.end(), rule);
    return pairs;
}

std::vector<int> PmergeMe::ExtractFirstElements(std::vector<Pair>& pairs)
{
    std::vector<int> result;
    for (size_t i = 0; i < pairs.size(); i++)
        result.push_back(pairs[i].first);
    return result;
}

std::vector<int> PmergeMe::ExtractSecondElements(std::vector<Pair>& pairs)
{
    std::vector<int> result;
    for (size_t i = 0; i < pairs.size(); i++)
        result.push_back(pairs[i].second);
    return result;
}

void PmergeMe::MergeInsertionSortVec(std::vector<int>& vec)
{
    std::vector<Pair> vecPairs = sortPairsVec(vec);
    std::vector<int> firstElements = ExtractFirstElements(vecPairs);
    std::vector<int> secondElements = ExtractSecondElements(vecPairs);
    bool hasUnpairedElement = (vec.size() % 2 != 0);
    int unpairedElement = hasUnpairedElement ? vec.back() : -1;
}

void PmergeMe::displayVec(std::vector<int>& vec)
{
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimeOfVec(unsigned long time)
{
    std::cout << "Time to process a range of " << _Myvector.size() << " elements with std::vector : " << time << " us" << std::endl;
}

// *** DEQUE METHODS ***//

void PmergeMe::fillDeq(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        _Mydeque.push_back(vec[i]);
}

std::deque<Pair> PmergeMe::sortPairsDeq(std::deque<int>& deq)
{
    std::deque<Pair> pairs;
    for (size_t i = 0; i < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    std::sort(pairs.begin(), pairs.end(), rule);
    return pairs;
}

std::deque<int> PmergeMe::ExtractFirstElements(std::deque<Pair>& pairs)
{
    std::deque<int> result;
    for (size_t i = 0; i < pairs.size(); i++)
        result.push_back(pairs[i].first);
    return result;
}

std::deque<int> PmergeMe::ExtractSecondElements(std::deque<Pair>& pairs)
{
    std::deque<int> result;
    for (size_t i = 0; i < pairs.size(); i++)
        result.push_back(pairs[i].second);
    return result;
}


void PmergeMe::MergeInsertionSortDeq(std::deque<int>& deq)
{
    std::deque<Pair> deqPairs = sortPairsDeq(deq);
    std::deque<int> firstElements = ExtractFirstElements(deqPairs);
    std::deque<int> secondElements = ExtractSecondElements(deqPairs);
    
}
