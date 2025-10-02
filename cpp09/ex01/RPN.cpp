#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) { (void)other; }

RPN &RPN::operator=(const RPN &other) 
{ 
    (void)other; 
    return *this; 
}

RPN::~RPN() {}

bool RPN::isNumber(const std::string &input)
{
    if (input.length() != 1 || !isdigit(input[0]))
        return false;
    return true;
}

bool RPN::isOperator(const std::string &input)
{
    if ((input == "+" || input == "-" || input == "*" || input == "/") && input.length() == 1)
        return true;
    return false;
}

void RPN::calculate(const std::string &input, std::stack<int> &stack)
{
    int x, y, res;

    if (RPN::isNumber(input))
        stack.push(atoi(input.c_str()));
    else if (isOperator(input))
    {
        switch(input[0])
        {
            case '+':
                if (stack.size() >= 2)
                {
                    x = stack.top();
                    stack.pop();
                    y = stack.top();
                    stack.pop();
                    res = y + x;
                    stack.push(res);
                }
                else
                    throw RPN::ArgumentError();
                break;
            case '-':
                if (stack.size() >= 2)
                {
                    x = stack.top();
                    stack.pop();
                    y = stack.top();
                    stack.pop();
                    res = y - x;
                    stack.push(res);
                }
                else
                    throw RPN::ArgumentError();
                break;
            case '*':
                if (stack.size() >= 2)
                {
                    x = stack.top();
                    stack.pop();
                    y = stack.top();
                    stack.pop();
                    res = y * x;
                    stack.push(res);
                }
                else
                    throw RPN::ArgumentError();
                break;
            case '/':
                if (stack.size() >= 2)
                {
                    x = stack.top();
                    stack.pop();
                    if (x == 0)
                        throw RPN::DivisionByZero();
                    y = stack.top();
                    stack.pop();
                    res = y / x;
                    stack.push(res);
                }
                else
                    throw RPN::ArgumentError();
                break;
            default:
                throw RPN::ArgumentError();
                break;
        }
    }
}

const char* RPN::ArgumentError::what() const throw()
{
    return "Error: Invalid number of arguments.";
}

const char* RPN::DivisionByZero::what() const throw()
{
    return "Error: Division by zero.";
}