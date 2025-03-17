#include "PhoneBook.hpp"

std::string ValidString(const std::string& str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::SearshCommand(PhoneBook& UserPhone){
    int i;
    int j;

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "first Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nick Name" << "|" << std::endl;
    std::cout << "--------------------------------------------\n";
    i = 0;
    while (i < 8)
    {
        if (!UserPhone.contacts[i].GetFirstName().empty())
        {
            std::cout << std::setw(10) << i << "|"
                      << ValidString(UserPhone.contacts[i].GetFirstName()) << "|"
                      << ValidString(UserPhone.contacts[i].GetLastName())<< "|"
                      << ValidString(UserPhone.contacts[i].GetNickName())<< "|" << std::endl; // i = 9; setw(10) << i "         9"
            std::cout << "--------------------------------------------\n";
        }
        i++;
    }
    while (1)
    {
        std::cout << "Enter index of Contact that you want more information about\n";
        if (!(std::cin >> j))
        {
            if (std::cin.eof())
                exit(1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // i should more about that
            std::cout << "Invalid Input\n";
            continue;
        }
        else if (j < 0 || j >= 8)
            std::cout << "Invalid Input\n";
        else if (!UserPhone.contacts[j].GetFirstName().empty())
        {
            std::cout << "First Name: " << UserPhone.contacts[j].GetFirstName() << std::endl;
            std::cout << "Last Name: " << UserPhone.contacts[j].GetLastName() << std::endl;
            std::cout << "Nick Name: " << UserPhone.contacts[j].GetNickName() << std::endl;
            std::cout << "Phone Number: " << UserPhone.contacts[j].GetPhoneNumber() << std::endl;
            std::cout << "Darkest Secret is: " << UserPhone.contacts[j].GetDarkestSecret() << std::endl;
            break;
        }
        else
            std::cout << "Empty contact!" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // i should more about that
}