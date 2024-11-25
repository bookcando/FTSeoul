/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:57:04 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/13 11:57:05 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	Contact		contact[8];
	PhoneBook	phonebook(contact);
	std::string	input;

	std::cout << "Hello! this is your phonebook app." << std::endl;
	std::cout << "supported commands : ADD / SEARCH / EXIT" << std::endl;
	while (1)
	{
		get_string_notempty("command : ", input);
		if (input == "ADD")
		{
			phonebook.add();
		}
		else if (input == "SEARCH")
		{
			phonebook.search();
		}
		else if (input == "EXIT")
		{
			break ;
		}
		else if (input != "")
		{
			std::cout << "not a valid command" << std::endl;
		}
	}
}
