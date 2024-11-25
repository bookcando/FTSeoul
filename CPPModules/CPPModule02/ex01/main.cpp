/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:56:16 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/26 13:07:52 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed const e( -42.42f );
	Fixed const f( 25165825 ); // impossible : 25bits long int
	Fixed const g( 8388607 ); // 011111111...1, 24 bit long
	Fixed const h( -8388608 ); // 100000000...0, 24 bit long
	Fixed const i( 4194304.5f ); // 2^22 + 2^-1 bit long
	
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << std::setprecision(10) << "f is " << f << std::endl;
	std::cout << std::setprecision(10) << "g is " << g << std::endl;
	std::cout << std::setprecision(10) << "h is " << h << std::endl;
	std::cout << std::setprecision(10) << "i is " << i << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	std::cout << "i is " << i.toInt() << " as integer" << std::endl;
	
	return 0;
}
