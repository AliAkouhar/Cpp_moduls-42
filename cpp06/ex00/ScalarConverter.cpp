#include "ScalarConverter.hpp"

//char tools

bool ScalarConverter::isChar(std::string str)
{
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

void ScalarConverter::convertChar(std::string str)
{
    char c = str[0];

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

bool ScalarConverter::isInt(std::string str)
{
    int i = 0;

    while (str[i])
    {
        if (str[0] == '-' || str[0] == '+')
            i++;
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::convertInt(std::string str)
{
    long long value = atoll(str.c_str());

    if (value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else if (value < -128 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

bool ScalarConverter::isDouble(std::string str)
{
    int i = 0;
    bool dot = false;
    bool digit = true;
    int len = str.length();
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    if (len < 2)
        return false;
    if (str[0] == '.' || str[len - 1] == '.')
        return false;
    if (str[0] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (std::isdigit(str[i]))
            digit = true;
        else if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else 
            return false;
        i++;
    }
    return digit;
}

void ScalarConverter::convertDouble(std::string str)
{
    double value = atof(str.c_str());
    int intValue = static_cast<int>(value);
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << str << "f" << std::endl;
        std::cout << "Double: " << str << std::endl;
        return;
    }
    if (intValue >= 32 && intValue <= 126)
    {
        std::cout << "Char: " << static_cast<char>(intValue) << std::endl;
    }
    else 
        std::cout << "char: non displayable" << std::endl;
    std::cout << "Int: " << intValue << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) <<  static_cast<double>(value) << std::endl;
}

bool ScalarConverter::isFloat(std::string str)
{
    int i = 0;
    bool dot = false;
    bool digit = true;
    int len = str.length();
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    if (len < 2 || str[len - 1] != 'f')
        return false;
    if (str[0] == '.' || str[len - 1] == '.')
        return false;
    if (str[0] == '-' || str[i] == '+')
        i++;
    while (i < len - 1)
    {
        if (std::isdigit(str[i]))
            digit = true;
        else if (str[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else 
            return false;
        i++;
    }
    return digit;
}

void ScalarConverter::convertFloat(std::string str)
{
    float value = atof(str.c_str());
    int intValue = static_cast<int>(value);
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << str << "f" << std::endl;
        std::cout << "Double: " << str << std::endl;
        return;
    }
    if (intValue >= 32 && intValue <= 126)
    {
        std::cout << "Char: " << static_cast<char>(intValue) << std::endl;
    }
    else 
        std::cout << "char: non displayable" << std::endl;
    std::cout << "Int: " << intValue << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) <<  static_cast<double>(value) << std::endl;
}

void ScalarConverter::Impossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    if (ScalarConverter::isChar(str))
        ScalarConverter::convertChar(str);
    else if (ScalarConverter::isInt(str))
        ScalarConverter::convertInt(str);
    else if (ScalarConverter::isDouble(str))
        ScalarConverter::convertDouble(str);
    else if (ScalarConverter::isFloat(str))
        ScalarConverter::convertFloat(str);
    else
        ScalarConverter::Impossible();
}