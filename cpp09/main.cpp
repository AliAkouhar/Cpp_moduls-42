#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    try
    {
        if (ac != 2)
            throw BitcoinExchange::ArgException();
        BitcoinExchange btc;
        btc.readData();
        for (std::map<std::string, float>::iterator it = btc.getDataBase().begin(); it != btc.getDataBase().end(); ++it) {
            std::cout << "Date: " << it->first << " | Value: " << it->second << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}