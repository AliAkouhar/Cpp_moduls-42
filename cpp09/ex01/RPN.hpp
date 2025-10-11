#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <exception>

class RPN
{
    private:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
    public:
        class ArgumentError : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class DivisionByZero : public std::exception
        {
            public:
                const char* what() const throw();
        };
        static void calculate(const std::string &input, std::stack<int> &stack);
        static bool isNumber(const std::string &input);
        static bool isOperator(const std::string &input);
};

#endif