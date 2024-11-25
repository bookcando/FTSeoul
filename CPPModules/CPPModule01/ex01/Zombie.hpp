/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:08:04 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/22 12:27:36 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private :
		std::string		name;

	public :
		void	announce( void );
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
