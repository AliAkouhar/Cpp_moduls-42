#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "<DEBUG>" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "<INFO>" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "<WARNING>" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "<ERROR>" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int getIndex(std::string level)
{
    int i;

    i = 0;
    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i < 4)
    {
        if (str[i] == level)
            return (i);
        i++;
    }
    return (-1);
}

void Harl::complain(std::string level)
{
    int i;

    i =  getIndex(level);
    void (Harl::*arr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    switch (i)
    {
    case 0:
        (this->*arr[0])();
        // fall through
    case 1:
        (this->*arr[1])();
        // fall through
    case 2:
        (this->*arr[2])();
        // fall through
    case 3:
        (this->*arr[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
    // i = 0;
    // while (i < 4)
    // {
    //     if (str[i] == level)
    //     {
    //         (this->*arr[i])();
    //         return ;
    //     }
    //     i++;
    // }
    // std::cout << "Invalaid level\n";

}