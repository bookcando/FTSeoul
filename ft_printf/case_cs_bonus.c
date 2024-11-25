/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_cs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:40:28 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 18:41:51 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	case_c(int c, t_flag *list)
{
	size_t	space_len;

	c = ((c % 256) + 256) % 256;
	space_len = 0;
	if (list->width)
		space_len = list->width - 1;
	if (list->minus)
		if (write(1, &c, 1) == -1)
			return (-1);
	if (write_c(space_len, ' ') == -1)
		return (-1);
	if (!(list->minus))
		if (write(1, &c, 1) == -1)
			return (-1);
	return (max(1, list->width));
}

size_t	case_s(unsigned char *c, t_flag *list)
{
	int		space_len;
	int		strlen;

	if (c == 0)
		c = (unsigned char *)("(null)\0");
	if (list->precision == 0 && list->dot)
		return (write_c(list->width, ' '));
	strlen = get_strlen(c);
	if (strlen == -1)
		return (-1);
	if (list->dot)
		strlen = min(strlen, list->precision);
	space_len = max(list->width, strlen) - strlen;
	if (list->minus)
		if (print_str(c, strlen) == -1)
			return (-1);
	if (write_c(space_len, ' ') == -1)
		return (-1);
	if (!(list->minus))
		if (print_str(c, strlen) == -1)
			return (-1);
	return (max(strlen + space_len, list->width));
}

int	print_str(unsigned char *c, size_t length)
{
	return (write(1, c, length));
}

int	get_strlen(unsigned char *c)
{
	size_t	len;

	len = 0;
	while (*c)
	{
		len++;
		c++;
		if (len >= 2147483647)
			return (-1);
	}
	return (len);
}
