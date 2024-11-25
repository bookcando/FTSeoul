/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:39:50 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 15:19:57 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "harlFilter : please enter your command" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cout << "harlFilter : too many arguments" << std::endl;
		return (1);
	}
	Harl bot;
	bot.complain(argv[1]);
	return (0);
}
