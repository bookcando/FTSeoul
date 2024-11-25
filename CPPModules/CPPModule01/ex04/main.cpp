/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:09:32 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 14:23:12 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	line_replace(std::string &line, const std::string &s1, const std::string &s2)
{
	int 			index = 0;
	int 			pass1 = s1.length();
	int 			pass2 = s2.length();
	std::string		temp_prev;
	std::string		temp_post;
	unsigned long	position = 0;

	while (1)
	{
		position = line.find(s1, index);
		if (position != std::string::npos)
		{
			temp_prev = line.substr(0, position);
			temp_post = line.substr(position + pass1);
			line = temp_prev + s2 + temp_post;
			index = position + pass2;
		}
		else
		{
			break ;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "invalid command, check your arguments" << std::endl;
		return (1);
	}
	std::string		filename = std::string(argv[1]);
	std::string		s1 = std::string(argv[2]);
	std::string		s2 = std::string(argv[3]);
	
	std::ifstream	infile(filename);
	if (!(infile.is_open()))
	{
		std::cout << "unable to open : " << filename << std::endl;
		return (1);
	}

	std::ofstream	outfile(filename + ".replace");
	if (!(outfile.is_open()))
	{
		std::cout << "unable to create : " << filename << ".replace" << std::endl;
		return (1);
	}

	std::string		line;
	while (std::getline(infile, line))
	{
		if (!(infile.eof()))
			line = line + "\n";
		line_replace(line, s1, s2);
		outfile << line;
	}
	infile.close();
	outfile.close();
}
