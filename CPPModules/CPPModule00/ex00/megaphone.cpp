/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:56:16 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/13 11:56:16 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int argv_index = 1; argv[argv_index]; argv_index++)
		{
			for (int char_index = 0; argv[argv_index][char_index]; char_index++)
			{
				argv[argv_index][char_index] = std::toupper(argv[argv_index][char_index]);
			}
		}
		for (int argv_index = 1; argv[argv_index]; argv_index++)
		{
			std::cout << argv[argv_index];
		}
		std::cout << std::endl;
	}
	return (0);
}
