/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:28:11 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/14 15:33:52 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>

class Harl
{
	private :
		std::string complaints[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public :
		Harl( void );
		void complain( std::string level );
};

#endif
