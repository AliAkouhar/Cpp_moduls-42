#include "PhoneBook.hpp"

int main()
{
    std::string cmd;
    PhoneBook userphone;

    while (1)
    {
        std::cout << "Enter a Command, ADD, SEARSH, EXIT" << std::endl;
        std::getline(std::cin, cmd);
        if (cmd.empty())
            continue;
        if (cmd == "ADD")
            userphone.AddCommand(userphone);
        else if (cmd == "SEARSH")
            userphone.SearshCommand(userphone);
        else if (cmd == "EXIT")
        {
            std::cout << "Exiting" << std::endl;
            return (0);
        }
        else
        {
            std::cout << "Invalide Input!!" << std::endl;
            continue;
        }
    }
    return (0);
}