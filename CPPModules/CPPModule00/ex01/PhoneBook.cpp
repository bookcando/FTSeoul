/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:08:13 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/12 20:08:13 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	&get_string_notempty(std::string prompt, std::string &temp_string)
{
	temp_string = "";
	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, temp_string);
		if ((temp_string).length())
		{
			break ;
		}
		if (!std::cin.good())
		{
			std::cout << "  " << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::clearerr(stdin);
			std::cin.clear();
		}
	}
	return (temp_string);
}

void	print_10char_rightaligned(std::string &text)
{
	if (text.length() >= 10)
		std::cout << text.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << text;
}

Contact::Contact() : exist(false) {}

bool Contact::is_exist()
{
	if (exist == true)
		return (true);
	return (false);
}

void	Contact::new_contact()
{
	exist = true;
	std::string temp_string;

	get_string_notempty("first name     : ", first_name);
	get_string_notempty("last name      : ", last_name);
	get_string_notempty("nickname       : ", nickname);
	get_string_notempty("phone number   : ", phone_number);
	get_string_notempty("darkest secret : ", darkest_secret);
}

void	Contact::info_full()
{
	if (exist == false)
	{
		std::cout << "invalid index(index not exist)" << std::endl;
		return ;
	}
	std::cout << "first name     : " << first_name << std::endl;
	std::cout << "last name      : " << last_name << std::endl;
	std::cout << "nickname       : " << nickname << std::endl;
	std::cout << "phone number   : " << phone_number << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}

void	Contact::info_search(int	data_index)
{
	if (exist == true)
		std::cout << std::setw(10) << data_index;
	else
		std::cout << "          ";
	std::cout << "|";
	print_10char_rightaligned(first_name);
	std::cout  << "|";
	print_10char_rightaligned(last_name);
	std::cout  << "|";
	print_10char_rightaligned(nickname);
	std::cout  << std::endl;
}

PhoneBook::PhoneBook(Contact *array) : contact(array), index(0) {}

void	PhoneBook::info_search() const
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int row = 0; row < 8; row++)
	{
		std::cout << "----------+----------+----------+----------" << std::endl;
		if (contact[row].is_exist())
			contact[row].info_search(row + 1);
		else
			break ;
	}
}

void	PhoneBook::add()
{
	contact[index].new_contact();
	index = (index + 1) % 8;
}

void	PhoneBook::search() const
{
	std::string temp_string;
	
	info_search();
	get_string_notempty("choose an index : ", temp_string);
	std::cout << ":" << temp_string << ":" << std::endl;
	if (temp_string[1] == 0 && temp_string[0] > '0' && temp_string[0] < '9')
	{
		contact[temp_string[0] - '0' - 1].info_full();
	}
	else
	{
		std::cout << "invalid index(index over range)" << std::endl;
	}
}
