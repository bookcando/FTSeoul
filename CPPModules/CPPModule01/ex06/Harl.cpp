/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:06 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 13:43:00 by minsulee         ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for " \
	<< "my 7XL-double-cheese-triple-pickle-specialketchup burger."\
	<< std::endl \
	<< "I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." \
	<< std::endl \
	<< "You didn\'t put enough bacon in my burger!" \
	<< std::endl \
	<< "If you did, I wouldn\'t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."\
	<< std::endl \
	<< "I\'ve been coming for years "\
	<< "whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!"\
	<< " I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain( std::string level )
{
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
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "harlFilter : INVALID COMMAND" << std::endl;
			return ;
	}
}
