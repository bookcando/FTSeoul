/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_dixuhelp1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:17:08 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 18:41:45 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	print_num_s(char sign, ssize_t num, int base_num, char *base_str)
{
	if (num == 0)
		return (0);
	else
	{
		if (print_num_s(sign, num / base_num, base_num, base_str) == -1)
			return (-1);
	}
	if (write(1, &(base_str[(num % base_num) * sign]), 1) == -1)
		return (-1);
	return (0);
}

int	print_num_u(size_t num, int base_num, char *base_str)
{
	if (num == 0)
		return (0);
	else
	{
		if (print_num_u(num / base_num, base_num, base_str) == -1)
			return (-1);
	}
	if (write(1, &(base_str[(num % base_num)]), 1) == -1)
		return (-1);
	return (0);
}
