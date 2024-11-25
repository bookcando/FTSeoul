#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

ScalarConverter::ScalarConverter() {
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    *this = copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    if (this == &copy)
        return *this;
    return *this;
}
ScalarConverter::~ScalarConverter() {
}

static bool checkStringValidity(const std::string &string, int &sign, bool &decimalPoint, bool &valueUnderDecimalPoint, bool &endF, long long &valueLongLong, double &valueDouble, bool valueLongLongValid) {
    size_t length = string.length();
    double underDecimal = 0.1;

    if (length == 0)
        return false;
    if (length == 1 && (string[0] == '+' || string[0] == '-'))
        return false;
    for (size_t i = 0; i < length; i++) {
        if (string[i] == '+' || string[i] == '-') {
            if (i != 0)
                return false;
            if (string[0] == '-')
                sign = -1;
            continue;
        }
        else if (string[i] == '.') {
            if (decimalPoint)
                return false;
            decimalPoint = true;
            continue;
        }
        else if (string[i] == 'f') {
            if (i != length - 1)
                return false;
            endF = true;
            continue;
        }
        else if (string[i] < '0' || string[i] > '9')
            return false;
        else if (valueUnderDecimalPoint == false && decimalPoint == true && string[i] != '0') {
            valueUnderDecimalPoint = true;
        }

        if (!decimalPoint) {
            if (valueLongLongValid == true) {
                valueLongLong = valueLongLong * 10 + sign * (string[i] - '0');
            }
            valueDouble = valueDouble * 10 + sign * (string[i] - '0');

            if (valueLongLong < INT_MIN || valueLongLong > INT_MAX)
                valueLongLongValid = false;
        }
        else {
            valueDouble = valueDouble + underDecimal * sign * (string[i] - '0');
            underDecimal /= 10;
        }
    }
    return true;
}

static int checkType(bool &valueUnderDecimalPoint, bool &endF) {
    if (valueUnderDecimalPoint == false)
        return 1; // int
    if (endF)
        return 2; // float
    return 3; // double
}

static std::string convertToString(const double &value) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(350) << value;
    std::string str = out.str();

    size_t end = str.find_last_not_of('0');
    if (end != std::string::npos) {
        str.erase(end + 1);
    }
    if (str[str.length() - 1] == '.') {
        str = str + "0";
    }
    else if (str.find('.') == std::string::npos) {
        str = str + ".0";
    }
    return str;
}
static std::string convertToString(const float &value) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(60) << value;
    std::string str = out.str();

    size_t end = str.find_last_not_of('0'); // the last character that is not '0'
    if (end != std::string::npos) {
        str.erase(end + 1);
    }
    if (str[str.length() - 1] == '.') {
        str = str + "0f";
    }
    else if (str.find('.') == std::string::npos) {
        str = str + ".0f";
    }
    else {
        str = str + "f";
    }
    return str;

}

void ScalarConverter::convert(const std::string &string) {

    int sign = 1;
    bool decimalPoint = false;
    bool valueUnderDecimalPoint = false;
    bool endF = false;
    long long valueLongLong = 0;
    double valueDouble = 0;
    bool valueLongLongValid = true;

    if (string == "nan" || string == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (string == "-inff" || string == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << string << std::endl;
        if (string == "-inff")
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: +inf" << std::endl;
        return;
    }
    if (string == "-inf" || string == "+inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << string << "f" << std::endl;
        std::cout << "double: " << string << std::endl;
        return;
    }

    //case 0: char input;
    if ((string.length() == 1) && (isprint(static_cast<int>(string[0]))) && (string[0] < '0' || string[0] > '9')) {
        std::cout << "char: '" << string[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(string[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(string[0]) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(string[0]) << std::endl;
        return;
    }

    if (string == ".f" || checkStringValidity(string, sign, decimalPoint, valueUnderDecimalPoint, endF, valueLongLong, valueDouble, valueLongLongValid) == false) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    int type = checkType(valueUnderDecimalPoint, endF);
    // 1. integer => char?, int, float, double
    // 2. float => float, double
    // 3. double => float, double
    if (type == 1) {
        if (valueLongLongValid == false)
            std::cout << "char: impossible" << std::endl;
        else if (valueLongLong < 0 || valueLongLong > CHAR_MAX)
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<int>(valueLongLong)))
            std::cout << "char: '" << static_cast<char>(valueLongLong) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (valueLongLongValid == false)
            std::cout << "int: impossible" << std::endl;
        else if (valueLongLong < INT_MIN || valueLongLong > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valueLongLong) << std::endl;

        float tempFloat = static_cast<float>(valueDouble);
        if (tempFloat == std::numeric_limits<float>::infinity())
            std::cout << "float: +inff" << std::endl;
        else if (tempFloat == -std::numeric_limits<float>::infinity())
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: " << convertToString(tempFloat) << std::endl;

        if (valueDouble == std::numeric_limits<double>::infinity())
            std::cout << "double: +inf" << std::endl;
        else if (valueDouble == -std::numeric_limits<double>::infinity())
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: " << convertToString(valueDouble) << std::endl;

    }
    else if (type == 2 || type == 3) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        float tempFloat = static_cast<float>(valueDouble);
        if (tempFloat == std::numeric_limits<float>::infinity())
            std::cout << "float: +inff" << std::endl;
        else if (tempFloat == -std::numeric_limits<float>::infinity())
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: " << convertToString(tempFloat) << std::endl;

        if (valueDouble == std::numeric_limits<double>::infinity())
            std::cout << "double: +inf" << std::endl;
        else if (valueDouble == -std::numeric_limits<double>::infinity())
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: " << convertToString(valueDouble) << std::endl;
    }
}
