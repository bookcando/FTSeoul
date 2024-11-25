/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:36:52 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/26 13:06:42 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}

Fixed::Fixed(const int raw_int) : value(0)
{
	std::cout << "Int constructor called" << std::endl;
	value = raw_int * (1 << fractional_bits);
}

Fixed::Fixed(const float raw_float) : value(0)
{
	std::cout << "Float constructor called" << std::endl;
	value = static_cast<int>(roundf(raw_float * (1 << fractional_bits)));
}

float	Fixed::toFloat( void ) const
{
	return ((static_cast<float>(value)) / (1 << fractional_bits));
}

int		Fixed::toInt( void ) const
{
	return (value / (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream& out, const Fixed &number)
{
	if (number.getRawBits() < 0 && number.toInt() == 0)
	{
		out << "-0";
	}
	else
	{
		out << number.toInt();
	}
	float fractional_part = (static_cast<float>(number.getRawBits() & 0x000000FF)) / (1 << FRACTIONAL_BITS);
	if (!fractional_part)
	{
		return (out);
	}
	else
	{
		if (number.getRawBits() < 0)
		{
			fractional_part = 1 - fractional_part;
		}
		std::ostringstream oss;
		oss << std::setprecision(8) << fractional_part;
		std::string fractional_part_str = oss.str();
		out << fractional_part_str.substr(1, fractional_part_str.find_last_not_of("0"));
	}
	return (out);
}
