/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:08:09 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/13 11:58:03 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

std::string	&get_string_notempty(std::string prompt, std::string &temp_string);
void		print_10char_rightaligned(std::string &text);

class Contact
{
	private :
		bool			exist;
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;

	public :
		Contact(void);
		bool 	is_exist(void);
		void	new_contact(void);
		void	info_full(void);
		void	info_search(int	data_index);
};

class PhoneBook
{
	private :
		Contact *contact;
		int		index;
		void	info_search() const;

	public :
		PhoneBook(Contact *array);
		void	add();
		void	search() const;
};

#endif
