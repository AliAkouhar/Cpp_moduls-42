#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <exception>

class BitcoinExchange {
    private:
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        std::map<std::string, float> getDataBase() const { return data; }

        void    readData();
        class ArgException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FileException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
    };
#endif