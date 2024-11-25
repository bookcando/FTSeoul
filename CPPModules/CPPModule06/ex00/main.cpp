#include "ScalarConverter.hpp"
// #include <iomanip>

void infTest();

int main(int argc, char* argv[]) {
    // ScalarConverter conv; // can't compile
    
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    } else {
        std::cout << "Usage: ./convert <value>" << std::endl;
        return 1;
    }
    // infTest();
    return 0;
    
}

// void infTest() {
//     float f = 10;
//     double d = 10;
//     char c = 10;
//     int i = 10;

//     try {

//         float ff = std::pow(f, 200);
//         double dd = std::pow(d, 200);
//         double ddd = std::pow(d, 310);
//         double mdd = std::pow(d, 200) * -1;
//         double mddd = std::pow(d, 310) * -1;
//         // char cc = std::pow(c, 200);
//         char cc = c * 100;
//         // int ii = std::pow(i, 200);
//         int ii = i * 2147483647;

//         float casted = static_cast<float>(dd);
//         float mcasted = static_cast<float>(mdd);

//         std::cout << "ff : " << ff << std::endl;
//         std::cout << "casted : " << casted << std::endl;
//         std::cout << "dd : " << dd << std::endl;
//         std::cout << "ddd : " << ddd << std::endl; // +inf
//         std::cout << "mdd : " << mdd << std::endl;
//         std::cout << "mddd : " << mddd << std::endl; // -inf
//         std::cout << "cc : " << cc << std::endl;
//         std::cout << "ii : " << ii << std::endl;

//         if (ddd == std::numeric_limits<double>::infinity())
//             std::cout << "ddd is infinity" << std::endl;
//         if (ddd == -std::numeric_limits<double>::infinity())
//             std::cout << "ddd is -infinity" << std::endl;
//         if (mddd == std::numeric_limits<double>::infinity())
//             std::cout << "mddd is infinity" << std::endl;
//         if (mddd == -std::numeric_limits<double>::infinity())
//             std::cout << "mddd is -infinity" << std::endl;

//         if (casted == std::numeric_limits<float>::infinity())
//             std::cout << "casted is infinity" << std::endl;
//         if (casted == -std::numeric_limits<float>::infinity())
//             std::cout << "casted is -infinity" << std::endl;
//         if (mcasted == std::numeric_limits<float>::infinity())
//             std::cout << "mcasted is infinity" << std::endl;
//         if (mcasted == -std::numeric_limits<float>::infinity())
//             std::cout << "mcasted is -infinity" << std::endl;


//         float a = 2147483640;
//         std::cout << "float a : " << std::fixed << std::setprecision(0) << a << std::endl;
//     }
//     catch (std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }

// }
