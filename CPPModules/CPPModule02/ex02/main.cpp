#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed d(-5.00390625f);
	Fixed e(5.781505f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "---------------------" << std::endl;

	Fixed c;
	c = Fixed(-1.2345f);

	std::cout << c << std::endl;
	std::cout << c.toInt() << std::endl;
	std::cout << c.toFloat() << std::endl;
	std::cout << (Fixed(0.015f) * Fixed(-1)) << std::endl;

	std::cout << "----------divide test" << std::endl;
	std::cout << (Fixed(2) / Fixed(1)) << std::endl;
	std::cout << (Fixed(10) / Fixed(1)) << std::endl;
	std::cout << (Fixed(100.5f) / Fixed(0.5f)) << std::endl;
	std::cout << (Fixed(100.5f) / Fixed(0)) << std::endl;
	std::cout << (Fixed(8388607)) << std::endl;
	std::cout << (Fixed(4000000) / Fixed(0.125f)) << std::endl;
	std::cout << (Fixed(0.015f) / Fixed(-1)) << std::endl;
	std::cout << (Fixed(-4194305.5f) / Fixed(-1)) << std::endl;
	std::cout << (Fixed(-8388609) / Fixed(1)) << std::endl;
	std::cout << (Fixed(-8388608) / Fixed(1)) << std::endl;
	std::cout << (Fixed(-8388607) / Fixed(1)) << std::endl;

	std::cout << "----------multiply test" << std::endl;
	std::cout << (Fixed(2) * Fixed(1)) << std::endl;
	std::cout << (Fixed(10) * Fixed(1)) << std::endl;
	std::cout << (Fixed(100.5f) * Fixed(0.5f)) << std::endl;
	std::cout << (Fixed(100.5f) * Fixed(0)) << std::endl;
	std::cout << (Fixed(8388607)) << std::endl;
	std::cout << (Fixed(4000000) * Fixed(0.125f)) << std::endl;
	std::cout << (Fixed(0.015f) * Fixed(-1)) << std::endl;
	std::cout << (Fixed(-4194305.5f) * Fixed(-1)) << std::endl;
	std::cout << (Fixed(109) * Fixed(208)) << std::endl;
	std::cout << (Fixed(99994) * Fixed(23405)) << std::endl;
	std::cout << (Fixed(-8388607) * Fixed(1)) << std::endl;

	std::cout << "----------add test" << std::endl;
	std::cout << (Fixed(2) + Fixed(1)) << std::endl;
	std::cout << (Fixed(10) + Fixed(1)) << std::endl;
	std::cout << (Fixed(100.5f) + Fixed(0.5f)) << std::endl;
	std::cout << (Fixed(100.5f) + Fixed(0)) << std::endl;
	std::cout << (Fixed(8388607)) << std::endl;
	std::cout << (Fixed(4000000) + Fixed(0.125f)) << std::endl;
	std::cout << (Fixed(0.015f) + Fixed(-1)) << std::endl;
	std::cout << (Fixed(-4194305.5f) + Fixed(-1)) << std::endl;
	std::cout << (Fixed(109) + Fixed(208)) << std::endl;
	std::cout << (Fixed(99994) + Fixed(23405)) << std::endl;
	std::cout << (Fixed(-8388607) + Fixed(1)) << std::endl;

	std::cout << "----------sub test" << std::endl;
	std::cout << (Fixed(2) - Fixed(1)) << std::endl;
	std::cout << (Fixed(10) - Fixed(1)) << std::endl;
	std::cout << (Fixed(100.5f) - Fixed(0.5f)) << std::endl;
	std::cout << (Fixed(100.5f) - Fixed(0)) << std::endl;
	std::cout << (Fixed(8388607)) << std::endl;
	std::cout << (Fixed(4000000) - Fixed(0.125f)) << std::endl;
	std::cout << (Fixed(0.015f) - Fixed(-1)) << std::endl;
	std::cout << (Fixed(-4194305.5f) - Fixed(-1)) << std::endl;
	std::cout << (Fixed(109) - Fixed(208)) << std::endl;
	std::cout << (Fixed(99994) - Fixed(23405)) << std::endl;
	std::cout << (Fixed(-8388607) - Fixed(1)) << std::endl;

	return 0;
}
