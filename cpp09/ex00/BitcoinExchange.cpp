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

int countPipe(const std::string &line)
{
    int count = 0;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == '|')
            count++;
    }
    if (count == 1)
        return 1;
    return 0;
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == std::string::npos) ? "" : str.substr(first, (last - first + 1));
}

int checkMinus(const std::string &date)
{
    int count = 0;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
        {
            count++;
            if (i == 0 || i == date.length() - 1 || !isdigit(date[i - 1]) || !isdigit(date[i + 1]))
                return false;
        }
    }
    return count == 2;
}

int is_valide_date(const std::string &date)
{
    if(!checkMinus(date))
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    if (m < 1 || m > 12 || d < 1 || d > 31 || y < 0 || y > 2025)
        return false;
    return true;
}

void parseFirstDate(const std::string &date)
{
    if (!is_valide_date(date))
        throw BitcoinExchange::InputException();
}

bool   checkDouble(std::string str)
{
    //! still need a lot of work
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            count++;
            if (i == 0 || i == str.length() - 1 || !isdigit(str[i - 1]) || !isdigit(str[i + 1]))
                return false;
        }
        if (!isdigit(str[i]) && str[i] != '.')
            return false;
    }
    if (count > 1)
        return false;
    return true;
}

void parseSecondDate(const std::string &value)
{
    if (!checkDouble(value))
        throw BitcoinExchange::InputException();
    double n = std::atof(value.c_str());
    if (n < 0 || n > 1000)
        throw BitcoinExchange::outOfRangeException();
}

void BitcoinExchange::calcule(const std::string &line)
{
    std::pair<std::string, std::string> pair;
    std::map<std::string, float>::iterator it;

    if (!countPipe(line))
        throw FormatException();
    pair.first = trim(line.substr(0, line.find('|')));
    pair.second = trim(line.substr(line.find('|') + 1));
    parseFirstDate(pair.first);
    if (pair.second.empty())
        throw BitcoinExchange::InputException();
    parseSecondDate(pair.second);
    it = data.lower_bound(pair.first);
    if (it == data.end() || it->first != pair.first)
    {
        if (it == data.begin())
            throw noEarlierDateException();
        --it;
    }
    float value = std::atof(pair.second.c_str());
    float rate = it->second;
    float multipl = rate * value;
    std::cout << pair.first << " => " << atof(pair.second.c_str()) << " = " << multipl << std::endl;
}

const std::map<std::string, float>& BitcoinExchange::getDataBase() const
{
    return data;
}

const char* BitcoinExchange::ArgException::what() const throw()
{
    return "ERROR: Bad Arguments\nUse : ./btc <INput file>\n";
}

const char* BitcoinExchange::FileException::what() const throw()
{
    return "ERROR: Could not open file.\n";
}

const char* BitcoinExchange::FormatException::what() const throw()
{
    return "ERROR: File format is incorrect.\n(First line should be: data | value)\n";
}

const char* BitcoinExchange::InputException::what() const throw()
{
    return "ERROR: Bad Input\n";
}

const char* BitcoinExchange::dateValueException::what() const throw()
{
    return "Error: Invalid date(year, month or day) value";
}

const char* BitcoinExchange::outOfRangeException::what() const throw()
{
    return "Error: too large a number.";
}

const char* BitcoinExchange::noEarlierDateException::what() const throw()
{
    return "Error: No earlier date";
}