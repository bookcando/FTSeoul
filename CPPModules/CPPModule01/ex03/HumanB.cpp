/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:27:48 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/14 14:28:37 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string input_name) : name(input_name), weapon(0) {}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	if (weapon)
		std::cout << weapon->getType();
	else
		std::cout << "Hands";
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &set)
{
	weapon = &set;
}
