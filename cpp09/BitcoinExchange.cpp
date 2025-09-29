#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->data = other.data;
    }
    return *this;
}

void BitcoinExchange::readData()
{
    std::ifstream file("data.csv");
    std::pair<std::string, float> pair;
    if (!file.is_open())
        throw FileException();
    std::string line;
    std::string date;
    float value;
    getline(file, line); // Skip header
    while(getline(file, line))
    {
        date = line.substr(0, line.find(','));
        value = std::atof(line.substr(line.find(',') + 1).c_str());
        pair = std::make_pair(date, value);
        data.insert(pair);
    }
}

const char* BitcoinExchange::ArgException::what() const throw()
{
    return "ERROR: Bad Arguments\nUse : ./btc <INput file>\n";
}

const char* BitcoinExchange::FileException::what() const throw()
{
    return "ERROR: Could not open file.\n";
}