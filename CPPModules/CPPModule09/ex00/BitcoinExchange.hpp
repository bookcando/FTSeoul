#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, double> _exchangeRates;
    std::map<std::string, std::string> _monthDays;


    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange& operator=(const BitcoinExchange &copy);

    void checkDateFormat(const std::string &date);
    void checkRateFormat(double rate);
    void initArrays();
    void checkInputFormat(const std::string &input);
    double rateFinder(const std::string &date);

public:
    explicit BitcoinExchange(const std::string &databaseFilename);
    ~BitcoinExchange();

    void rateCalculator(const std::string &inputFile);

    class InvalidFormatException : public std::exception {
        private:
            std::string _message;
        public:
            explicit InvalidFormatException(const std::string &message);
            virtual const char *what() const throw();
            virtual ~InvalidFormatException() throw();
    };
    class FileException : public std::exception {
        private:
            std::string _message;
        public:
            explicit FileException(const std::string &message);
            virtual const char *what() const throw();
            virtual ~FileException() throw();
    };
};

#endif
