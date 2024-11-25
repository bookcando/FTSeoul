/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:36:52 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/26 13:35:14 by minsulee         ###   ########.fr       */
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
	return (static_cast<float>(value) / (1 << fractional_bits));
}

int		Fixed::toInt( void ) const
{
	return (static_cast<int>(value) / (1 << fractional_bits));
}

bool			Fixed::operator>(const Fixed &post) const
{
	if (value > post.getRawBits())
		return (true);
	return (false);
}

bool			Fixed::operator<(const Fixed &post) const
{
	if (value < post.getRawBits())
		return (true);
	return (false);
}

bool			Fixed::operator>=(const Fixed &post) const
{
	if (value >= post.getRawBits())
		return (true);
	return (false);
}

bool			Fixed::operator<=(const Fixed &post) const
{
	if (value <= post.getRawBits())
		return (true);
	return (false);
}

bool			Fixed::operator==(const Fixed &post) const
{
	if (value == post.getRawBits())
		return (true);
	return (false);
}

bool			Fixed::operator!=(const Fixed &post) const
{
	if (value != post.getRawBits())
		return (true);
	return (false);
}

Fixed			Fixed::operator+(const Fixed &post) const
{
	Fixed temp;

	temp.setRawBits(value + post.getRawBits());
	return (temp);
}

Fixed			Fixed::operator-(const Fixed &post) const
{
	Fixed temp;

	temp.setRawBits(value - post.getRawBits());
	return (temp);
}

Fixed			Fixed::operator*(const Fixed &post) const
{
	Fixed temp;
	long prev_value = static_cast<long>(this->value);
	long post_value = static_cast<long>(post.getRawBits());

	temp.setRawBits(prev_value * post_value / (1 << fractional_bits));
	return (temp);
}
Fixed			Fixed::operator/(const Fixed &post) const
{
	Fixed temp;

	if (post.getRawBits() == 0)
	{
		temp.setRawBits(INT_MAX);
		return (temp);
	}
	long prev_value = static_cast<long>(this->value);
	long post_value = static_cast<long>(post.getRawBits());

	temp.setRawBits(prev_value * (1 << fractional_bits) / post_value);
	return (temp);
}

Fixed			&Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed			&Fixed::operator--()
{
	this->value--;
	return (*this);
}

const Fixed		Fixed::operator++(int)
{
	Fixed temp = *this;

	this->value++;
	return (temp);
}

const Fixed		Fixed::operator--(int)
{
	Fixed temp = *this;

	this->value--;
	return (temp);
}

Fixed			&Fixed::min(Fixed &prev, Fixed &post)
{
	if (prev.getRawBits() < post.getRawBits())
		return (prev);
	return (post);
}

const Fixed		&Fixed::min(const Fixed &prev, const Fixed &post)
{
	if (prev.getRawBits() < post.getRawBits())
		return (prev);
	return (post);
}

Fixed			&Fixed::max(Fixed &prev, Fixed &post)
{
	if (prev.getRawBits() > post.getRawBits())
		return (prev);
	return (post);
}

const Fixed		&Fixed::max(const Fixed &prev, const Fixed &post)
{
	if (prev.getRawBits() > post.getRawBits())
		return (prev);
	return (post);
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
