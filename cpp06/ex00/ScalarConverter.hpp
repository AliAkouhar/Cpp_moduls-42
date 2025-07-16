#ifndef SCALARCONVERTER_HPP
#define SCALERCONVERTER_HPP


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        static void convert(std::string str);
        //char
        static bool isChar(std::string str);
        static void convertChar(std::string str);
        //int
        static bool isInt(std::string str);
        static void convertInt(std::string str);
        //float
        static bool isFloat(std::string str);
        static void convertFloat(std::string str);
        //double
        static bool isDouble(std::string str);
        static void convertDouble(std::string str);
        //impossible
        static void Impossible();
};

#endif