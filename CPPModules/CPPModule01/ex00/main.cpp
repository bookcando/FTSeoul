/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:08:54 by minsulee          #+#    #+#             */
/*   Updated: 2023/06/23 10:49:23 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*scope_test(void)
{
	std::string sad_zombie_name = "Zombie which only exists in this scope";
	std::string happy_zombie_name = "new zombie from newZombie";

	randomChump(sad_zombie_name);
	return (newZombie(happy_zombie_name));
}

int main(void)
{
	std::string	three = "three";
	std::string	four = "four";
	Zombie	z_one("one");
	Zombie	z_two("two");
	Zombie	z_three(three);
	Zombie	*z_four = new Zombie(four);
	Zombie	*z_five = new Zombie("five");
	Zombie	*z_six;

	std::cout << "THIS IS MAIN" << std::endl;
	z_one.announce();
	z_two.announce();
	z_six = scope_test();
	z_six->announce();
	z_three.announce();
	z_four->announce();
	z_five->announce();
	delete (z_five);
	delete (z_four);
	delete (z_six);
}
