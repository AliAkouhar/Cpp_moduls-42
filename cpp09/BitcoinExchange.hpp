#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        const std::map<std::string, float>& getDataBase() const;
        void calcule(const std::string &line);

        void    readData();
        class ArgException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FileException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class FormatException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class InputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class dateValueException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        class outOfRangeException : public std::exception
        {
            public :
                const char* what() const throw();
        };

        class noEarlierDateException : public std::exception
        {
            public :
                const char* what() const throw();
        };
    };
#endif