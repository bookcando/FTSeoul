/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:28:13 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 14:47:03 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	complaints[0] = "DEBUG";
	complaints[1] = "INFO";
	complaints[2] = "WARNING";
	complaints[3] = "ERROR";
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for " \
	<< "my 7XL-double-cheese-triple-pickle-specialketchup burger."\
	<< " I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." \
	<< " You didn\'t put enough bacon in my burger!" \
	<< " If you did, I wouldn\'t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free."\
	<< " I\'ve been coming for years "\
	<< "whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable!"\
	<< " I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void	(Harl::*function_pointer)(void);
	int		index = 0;

	while (index < 4)
	{
		if (complaints[index] == level)
			break ;
		++index;
	}
	switch (index)
	{
		case 0:
			function_pointer = &Harl::debug;
			break ;
		case 1:
			function_pointer = &Harl::info;
			break ;
		case 2:
			function_pointer = &Harl::warning;
			break ;
		case 3:
			function_pointer = &Harl::error;
			break ;
		default:
			return ;
	}
	(this->*function_pointer)();
}
