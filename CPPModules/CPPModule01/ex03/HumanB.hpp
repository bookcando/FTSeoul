/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:27:50 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/14 14:28:09 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	private :
		std::string	name;
		Weapon		*weapon;

	public :
		HumanB(std::string input_name);
		void		setWeapon(Weapon &set);
		void		attack();

};

#endif
