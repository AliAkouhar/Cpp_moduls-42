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
        std::ifstream file(av[1]);
        if (!file.is_open())
            throw BitcoinExchange::FileException();
        std::string line;
        getline(file, line);
        if (line != "data | value")
        {
            file.close();
            throw BitcoinExchange::FormatException();
        }
        while (getline(file, line))
        {
            std::cout << line << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}