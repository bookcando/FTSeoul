/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:28:49 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/14 14:29:06 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string initial_type) : type(initial_type) {}

const std::string &Weapon::getType(void)
{
	return (type);
}

void Weapon::setType(std::string input)
{
	type = input;
}
