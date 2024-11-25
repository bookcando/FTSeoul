/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:08:12 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/14 16:09:03 by minsulee         ###   ########.fr       */
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
		~Zombie();
};

void	randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif
