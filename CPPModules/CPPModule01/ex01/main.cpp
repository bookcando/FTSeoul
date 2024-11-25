/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:07:56 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 10:51:12 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie		z_one("one");
	Zombie		*zombies;
	const int	horde_amount = 5;

	zombies = zombieHorde(horde_amount, "ZPARTY");
	for (int index = 0; index < horde_amount; ++index)
	{
		zombies[index].announce();
	}
	z_one.announce();

	delete[] zombies;
}
