#include "Span.hpp"

int main()
{
    std::cout << "--- Subject Example Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Large Test with 10,000 numbers ---" << std::endl;
    try {
        srand(time(0));
        std::vector<int> largeVec;
        Span bigSpan(10000);
        for (int i = 0; i < 10000; i++)
            largeVec.push_back(rand() % 100000);
        bigSpan.fillSpan(largeVec.begin(), largeVec.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test: Overfilling ---" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test: Not Enough Numbers ---" << std::endl;
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // Should throw
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}