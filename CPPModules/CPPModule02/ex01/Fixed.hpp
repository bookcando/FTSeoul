/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:55:45 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/26 12:59:46 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#define FRACTIONAL_BITS 8

class	Fixed
{
	private :
		int					value;
		static const int	fractional_bits = FRACTIONAL_BITS;

	public :
		Fixed();
		Fixed(const Fixed &copy);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed(const int raw_int);
		Fixed(const float raw_float);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream& out, const Fixed &number);

#endif
