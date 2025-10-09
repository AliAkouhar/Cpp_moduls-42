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
    fillDeq(vec);
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
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
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

std::vector<size_t> PmergeMe::getJacobOrderVec(size_t size)
{
    std::vector<size_t> order;
    if (size == 0)
        return order;
    std::vector<size_t> jacobSuite;
    jacobSuite.push_back(1);
    size_t j1 = 1, j2 = 0;
    while(1)
    {
        size_t next = j1 + (2 * j2);
        if (next >= size)
            break;
        jacobSuite.push_back(next);
        j1 = j2;
        j2 = next;
    }
    std::vector<bool> inserted(size, false);
    for (size_t i = 0; i < jacobSuite.size(); i++)
    {
        size_t j = jacobSuite[i];
        if (j < size && !inserted[j])
        {
            order.push_back(j);
            inserted[j] = true;
        }
        size_t start = (i == 0) ? 0 : jacobSuite[i - 1] + 1;
        for (ssize_t k = j - 1; k >= static_cast<ssize_t>(start); k--)
        {
            if (!inserted[k])
            {
                order.push_back(k);
                inserted[k] = true;
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        if (!inserted[i])
        {
            order.push_back(i);
            inserted[i] = true;
        }
    }
    return order;
}

void PmergeMe::InsertWithJacobOrderVec(std::vector<int>& firstElements, std::vector<int>& secondElements)
{
    std::vector<size_t> jacobOrder = getJacobOrderVec(firstElements.size());
    for (size_t i = 0; i < jacobOrder.size(); i++)
    {
        int value = firstElements[jacobOrder[i]];
        std::vector<int>::iterator it = std::lower_bound(secondElements.begin(), secondElements.end(), value);
        secondElements.insert(it, value);
    }
}

void PmergeMe::insertUnpairedElementVec(std::vector<int>& secondElements, int unpairedElement)
{
    std::vector<int>::iterator it = std::lower_bound(secondElements.begin(), secondElements.end(), unpairedElement);
    secondElements.insert(it, unpairedElement);
}

void PmergeMe::MergeInsertionSortVec(std::vector<int>& vec)
{
    std::vector<Pair> vecPairs = sortPairsVec(vec);
    std::vector<int> firstElements = ExtractFirstElements(vecPairs);
    std::vector<int> secondElements = ExtractSecondElements(vecPairs);
    bool hasUnpairedElement = (vec.size() % 2 != 0);
    int unpairedElement = hasUnpairedElement ? vec.back() : -1;
    InsertWithJacobOrderVec(firstElements, secondElements);
    if (hasUnpairedElement)
        insertUnpairedElementVec(secondElements, unpairedElement);
    vec = secondElements;
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
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
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


std::deque<size_t> PmergeMe::getJacobOrderDeq(size_t size)
{
    std::deque<size_t> order;
    if (size == 0)
        return order;
    std::deque<size_t> jacobSuite;
    jacobSuite.push_back(1);
    size_t j1 = 1, j2 = 0;
    while(1)
    {
        size_t next = j1 + (2 * j2);
        if (next >= size)
            break;
        jacobSuite.push_back(next);
        j1 = j2;
        j2 = next;
    }
    std::deque<bool> inserted(size, false);
    for (size_t i = 0; i < jacobSuite.size(); i++)
    {
        size_t j = jacobSuite[i];
        if (j < size && !inserted[j])
        {
            order.push_back(j);
            inserted[j] = true;
        }
        size_t start = (i == 0) ? 0 : jacobSuite[i - 1] + 1;
        for (ssize_t k = j - 1; k >= static_cast<ssize_t>(start); k--)
        {
            if (!inserted[k])
            {
                order.push_back(k);
                inserted[k] = true;
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        if (!inserted[i])
        {
            order.push_back(i);
            inserted[i] = true;
        }
    }
    return order;
}

void PmergeMe::InsertWithJacobOrderDeq(std::deque<int>& firstElements, std::deque<int>& secondElements)
{
    std::deque<size_t> jacobOrder = getJacobOrderDeq(firstElements.size());
    for (size_t i = 0; i < jacobOrder.size(); i++)
    {
        int value = firstElements[jacobOrder[i]];
        std::deque<int>::iterator it = std::lower_bound(secondElements.begin(), secondElements.end(), value);
        secondElements.insert(it, value);
    }
}

void PmergeMe::insertUnpairedElementDeq(std::deque<int>& secondElements, int unpairedElement)
{
    std::deque<int>::iterator it = std::lower_bound(secondElements.begin(), secondElements.end(), unpairedElement);
    secondElements.insert(it, unpairedElement);
}

void PmergeMe::displayTimeOfDeq(unsigned long time)
{
    std::cout << "Time to process a range of " << _Mydeque.size() << " elements with std::deque : " << time << " us" << std::endl;
}

void PmergeMe::MergeInsertionSortDeq(std::deque<int>& deq)
{
    std::deque<Pair> deqPairs = sortPairsDeq(deq);
    std::deque<int> firstElements = ExtractFirstElements(deqPairs);
    std::deque<int> secondElements = ExtractSecondElements(deqPairs);
    bool hasUnpairedElement = (deq.size() % 2 != 0);
    int straggler = hasUnpairedElement ? deq.back() : -1;

    InsertWithJacobOrderDeq(firstElements, secondElements);
    if (hasUnpairedElement)
        insertUnpairedElementDeq(secondElements, straggler);
    deq = secondElements;
}
