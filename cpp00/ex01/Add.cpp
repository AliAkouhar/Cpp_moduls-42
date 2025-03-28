#include "PhoneBook.hpp"

std::string FillFirstName()
{
    std::string Input;
    while(1)
    {
        std::cout << "Enter First Name" << std::endl;
        std::getline(std::cin, Input);
        if (std::cin.eof())
            exit(1);
        if (Input.empty())
            continue;
        else
            break;
    }
    return (Input);
}

std::string FillLastName()
{
    std::string Input;
    while(1)
    {
        std::cout << "Enter Last Name" << std::endl;
        std::getline(std::cin, Input);
        if (std::cin.eof())
            exit(1);
        if (Input.empty())
            continue;
        else
            break;
    }
    return (Input);
}

std::string FillNickName()
{
    std::string Input;
    while(1)
    {
        std::cout << "Enter Nick Name" << std::endl;
        std::getline(std::cin, Input);
        if (std::cin.eof())
            exit(1);
        if (Input.empty())
            continue;
        else
            break;
    }
    return (Input);
}

std::string FillPhoneNumber()
{
    std::string Input;
    while(1)
    {
        std::cout << "Enter Phone Number" << std::endl;
        std::getline(std::cin, Input);
        if (std::cin.eof())
            exit(1);
        if (Input.empty())
            continue;
        else
            break;
    }
    return (Input);
}

std::string FillSecret()
{
    std::string Input;
    while(1)
    {
        std::cout << "Enter Your Darkest Secret" << std::endl;
        std::getline(std::cin, Input);
        if (std::cin.eof())
            exit(1);
        if (Input.empty())
            continue;
        else
            break;
    }
    return (Input);
}

void PhoneBook::AddCommand(PhoneBook& UserPhone)
{
    Contact UserContact;
    UserContact.SetFirstName(FillFirstName());
    UserContact.SetLastName(FillLastName());
    UserContact.SetNickName(FillNickName());
    UserContact.SetPhoneNumber(FillPhoneNumber());
    UserContact.SetDarkestSecret(FillSecret());

    UserPhone.SetContact(UserContact);
}