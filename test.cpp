#include <iostream>

int main()
{
    std::string str = "1290";
    std::string str2 = "0300";
    // str2.pop_back();
    // std::cout << str2 << std::endl;
    std::cout << "the biggest is " << (str > str2 ? str : str2) << std::endl;
}