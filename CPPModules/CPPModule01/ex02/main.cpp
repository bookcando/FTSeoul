/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:09:11 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 13:31:55 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string a_string_variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &a_string_variable;
	std::string &stringREF = a_string_variable;

	std::cout << &a_string_variable << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &(stringREF) << std::endl;

	std::cout << a_string_variable << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
