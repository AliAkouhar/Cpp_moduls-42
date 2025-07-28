#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // Test const_iterator
    std::cout << "\nTesting const_iterator:" << std::endl;
    const MutantStack<int> constStack = mstack;
    MutantStack<int>::const_iterator cit = constStack.begin();
    MutantStack<int>::const_iterator cite = constStack.end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    return 0;
}