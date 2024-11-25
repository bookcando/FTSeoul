/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:28:17 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/14 15:39:06 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl bot;

	std::cout << "BEEP BEEP" << std::endl;
	bot.complain("BLAH BLAH");
	std::cout << "TEST 1 FINISHED" << std::endl;
	bot.complain("INFO");
	std::cout << "TEST 2 FINISHED" << std::endl;
	bot.complain("ERROR");
	std::cout << "TEST 3 FINISHED" << std::endl;
	bot.complain("DEBUG");
	std::cout << "TEST 4 FINISHED" << std::endl;
	bot.complain("WARNING");
	std::cout << "TEST 5 FINISHED" << std::endl;
	bot.complain("BLAH BLAH");
	std::cout << "TEST 6 FINISHED" << std::endl;
	return (0);
}
