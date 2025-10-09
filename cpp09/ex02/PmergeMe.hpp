#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <climits>
#include <sys/time.h>


typedef std::pair<int, int> Pair;

class PmergeMe
{
    private:
        std::vector<int>    _Myvector;
        std::deque<int>     _Mydeque;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        PmergeMe(std::vector<int> vec);
        void    sort(int argc, char** argv);
        void    MergeInsertionSort();
        void    displayFirstline();
        //Vector Methods
        void fillVec(std::vector<int> vec);
        void MergeInsertionSortVec(std::vector<int>& vec);
        std::vector<Pair> sortPairsVec(std::vector<int>& vec);
        std::vector<int> ExtractFirstElements(std::vector<Pair>& pairs);
        std::vector<int> ExtractSecondElements(std::vector<Pair>& pairs);
        void displayVec(std::vector<int>& vec);
        void displayTimeOfVec(unsigned long time);
        void InsertWithJacobOrderVec(std::vector<int>& firstElements, std::vector<int>& secondElements);
        void insertUnpairedElementVec(std::vector<int>& secondElements, int unpairedElement);
        std::vector<size_t> getJacobOrderVec(size_t size);
        //Deque Methods

        void fillDeq(std::vector<int> vec);
        void MergeInsertionSortDeq(std::deque<int>& deq); // to make
        void displayTimeOfDeq(unsigned long time); // to make
        std::deque<Pair> sortPairsDeq(std::deque<int>& deq);
        std::deque<int> ExtractFirstElements(std::deque<Pair>& pairs);
        std::deque<int> ExtractSecondElements(std::deque<Pair>& pairs);
        void InsertWithJacobOrderDeq(std::deque<int>& firstElements, std::deque<int>& secondElements);
        void insertUnpairedElementDeq(std::deque<int>& secondElements, int unpairedElement);
        std::deque<size_t> getJacobOrderDeq(size_t size);

        class InvalidArgumentException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "Error: Invalid argument";
            }
        };
    };
    std::vector<int> parseArgs(std::vector<std::string>& args);
    void checkDigit(std::string str);
    std::vector<int> convertStringsToIntegers(const std::vector<std::string>& args);
    bool rule(const Pair& a, const Pair& b);

#endif