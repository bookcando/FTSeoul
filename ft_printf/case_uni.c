/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_uni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:27:59 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 18:25:26 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_sign(t_flag *list, char sign)
{
	if (sign == -1)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	else if (list->plus)
	{
		if (write(1, "+", 1) == -1)
			return (-1);
	}
	else
	{
		if (write(1, " ", 1) == -1)
			return (-1);
	}
	return (0);
}

int	width_filler(size_t numlen, t_flag *list)
{
	if (list->dot)
	{
		if (write_c(max(list->width, numlen) - numlen, ' ') == -1)
			return (-1);
	}
	else
	{
		if (write_c(max(list->width, numlen) - numlen, '0') == -1)
			return (-1);
	}
	return (0);
}

int	write_c(size_t length, unsigned char c)
{
	size_t	retnum;

	retnum = length;
	while (length-- > 0)
		if (write(1, &c, 1) == -1)
			return (-1);
	return (retnum);
}
