#include "BitcoinExchange.hpp"

BitcoinExchange::InvalidFormatException::InvalidFormatException(const std::string &message) : _message(message) {}
const char *BitcoinExchange::InvalidFormatException::what() const throw() {
    return _message.c_str();
}
BitcoinExchange::InvalidFormatException::~InvalidFormatException() throw() {}

BitcoinExchange::FileException::FileException(const std::string &message) : _message(message) {}
const char *BitcoinExchange::FileException::what() const throw() {
    return _message.c_str();
}
BitcoinExchange::FileException::~FileException() throw() {}

void BitcoinExchange::checkDateFormat(const std::string &date) {
    if (date.size() != 10) {
        throw InvalidFormatException("Invalid date format(size).");
    }
    if (date[4] != '-' || date[7] != '-') {
        throw InvalidFormatException("Invalid date format(dash).");
    }
    if (!(isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3]) &&
          isdigit(date[5]) && isdigit(date[6]) && isdigit(date[8]) && isdigit(date[9]))) {
        throw InvalidFormatException("Invalid date format(digit).");
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (month < "01" || month > "12") {
        throw InvalidFormatException("Invalid date format(month).");
    }
    if (day < "01" || day > _monthDays[month]) {
        throw InvalidFormatException("Invalid date format(date not exists).");
    }
    if (month == "02" && day == "29") {
        std::istringstream yearStream(year);
        int yearInt;
        yearStream >> yearInt;
        if (yearStream.fail() || !yearStream.eof()) {
            throw InvalidFormatException("Invalid date format(year).");
        }
        if (!((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)) {
            throw InvalidFormatException("Invalid date format(date not exists(02-29)).");
        }
    }
}

void BitcoinExchange::checkRateFormat(double rate) {
    if (rate < 0) {
        throw InvalidFormatException("Invalid rate format(negative).");
    }
    if (rate == std::numeric_limits<double>::infinity()) {
        throw InvalidFormatException("Invalid rate format(infinity).");
    }
    if (rate == -std::numeric_limits<double>::infinity()) {
        throw InvalidFormatException("Invalid rate format(-infinity).");
    }
}

void BitcoinExchange::initArrays() {
    _monthDays["01"] = "31";
    _monthDays["02"] = "29";
    _monthDays["03"] = "31";
    _monthDays["04"] = "30";
    _monthDays["05"] = "31";
    _monthDays["06"] = "30";
    _monthDays["07"] = "31";
    _monthDays["08"] = "31";
    _monthDays["09"] = "30";
    _monthDays["10"] = "31";
    _monthDays["11"] = "30";
    _monthDays["12"] = "31";
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFilename)
{
    initArrays();

    std::ifstream dbFile(databaseFilename.c_str());
    if (!dbFile.is_open()) {
        throw FileException("could not open file(database file).");
    }

    std::string header;
    std::getline(dbFile, header);
    if (header != "date,exchange_rate") {
        throw InvalidFormatException("Invalid DB Format.");
    }

    std::string line;
    while (std::getline(dbFile, line)) {
        if (line.size() == 0)
            continue;
        std::istringstream ss(line);
        std::string date;
        double exchangeRate;

        std::getline(ss, date, ',');
        ss >> std::noskipws >> exchangeRate;
        if (ss.fail() || !ss.eof()) {
            throw InvalidFormatException("Invalid DB Format.");
        }

        checkDateFormat(date);
        checkRateFormat(exchangeRate);
        if (_exchangeRates.find(date) != _exchangeRates.end()) {
           throw InvalidFormatException("Invalid date format(duplicate).");
        }
        _exchangeRates[date] = exchangeRate;
    }

    if (dbFile.bad()) {
        throw FileException("error on reading database file.");
    }
    if (!dbFile.eof() && dbFile.fail()) {
        throw FileException("error on reading database file.");
    }
    if (_exchangeRates.size() == 0) {
        throw InvalidFormatException("No exchange rate data.");
    }
    line.clear();
}

BitcoinExchange::~BitcoinExchange() {};
BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    (void)copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    (void)copy;
    return *this;
}

double BitcoinExchange::rateFinder(const std::string &date) {

    std::map<std::string, double>::iterator it2 = _exchangeRates.upper_bound(date);
    if (it2 == _exchangeRates.begin()) {
        throw InvalidFormatException("Error: Data not found(before the first date of the db).");
    }
    --it2;
    return it2->second;
}

static std::string formatDouble(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(7) << value;

    std::string str = ss.str();
    while (str.size() > 0 && str[str.size() - 1] == '0') {
        str.erase(str.size() - 1);
    }
    if (str.size() > 0 && str[str.size() - 1] == '.') {
        str.erase(str.size() - 1);
    }
    if (str == "-0") {
        str = "0";
    }
    return str;
}

void BitcoinExchange::rateCalculator(const std::string &inputFilename) {
    if (inputFilename.size() == 0) {
        throw FileException("could not open file(input file).");
    }

    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile.is_open()) {
        throw FileException("could not open file(input file).");
    }


    std::string header;
    std::getline(inputFile, header);
    if (header != "date | value") {
        throw InvalidFormatException("Invalid input file Format.");
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.size() == 0)
            continue;
        if (line.size() <= 13) {
            std::cout << "Error: Invalid input format(length). => " << line << std::endl;
            continue;
        }
        if (_exchangeRates.size() == 0) {
            std::cout << "Error: No exchange rate data." << std::endl;
            continue;
        }

        std::istringstream ss(line);
        std::string date;
        std::istringstream valueSs;
        double amount = 0;

        date = line.substr(0, 10);
        if (line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
            std::cout << "Error: Invalid input format. => " << line << std::endl;
            continue;
        }
        valueSs.str(line.substr(13));
        valueSs >> std::noskipws >> amount;
        if (valueSs.fail() || !valueSs.eof()) {
            std::cout << "Error: Invalid input format(invalid value format). => " << line << std::endl;
            continue;
        }

        try {
            checkDateFormat(date);
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            continue;
        }
        
        if (amount < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (amount > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            double rate = rateFinder(date);
            double result = rate * amount;
            std::cout << std::fixed << date << " => " << formatDouble(amount) << " = " << formatDouble(result) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    if (inputFile.bad() || (!inputFile.eof() && inputFile.fail())){
        throw FileException("error on reading file.");
    }
}
