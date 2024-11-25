/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_flag_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:47:49 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 18:41:39 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	flag_get(const char **string, t_flag *list)
{
	flag_init(list);
	while (is_flag(string, list))
		(*string)++;
	list->format = **string;
	if (flag_check(list) == -1)
		return (-1);
	return (1);
}

int	is_flag(const char **string, t_flag *list)
{
	if (**string == '#')
		(list->sharp)++;
	else if (**string == '0')
		(list->zero)++;
	else if (**string == '-')
		(list->minus)++;
	else if (**string == ' ')
		(list->space)++;
	else if (**string == '+')
		(list->plus)++;
	else if (**string >= '1' && **string <= '9')
		(list->width) = pos_atoi(string);
	else if (**string == '.')
	{
		(list->dot)++;
		(*string)++;
		if (**string >= '0' && **string <= '9')
			(list->precision) = pos_atoi(string);
		else
			(*string)--;
	}
	else
		return (0);
	return (1);
}

int	pos_atoi(const char **string)
{
	ssize_t	ret_num;
	int		sign;

	ret_num = 0;
	sign = 0;
	while (**string >= '0' && **string <= '9')
	{
		ret_num = ret_num * 10 + (**string - '0');
		(*string)++;
		if (ret_num >= 2147483647)
			sign = 1;
	}
	(*string)--;
	if (sign)
		return (-1);
	return ((int)ret_num);
}

int	flag_check(t_flag *list)
{
	if (list->precision < 0 || list->width < 0)
		return (-1);
	if (list->sharp > 1)
		list->sharp = 1;
	if (list->plus > 1)
		list->plus = 1;
	if (list->plus == 1)
		list->space = 0;
	if (list->space > 1)
		list->space = 1;
	if (list->minus > 1)
		list->minus = 1;
	if (list->minus)
		list->zero = 0;
	if (list->zero > 1)
		list->zero = 1;
	if (list->dot > 1)
		return (-1);
	return (1);
}

void	flag_init(t_flag *list)
{
	list->sharp = 0;
	list->plus = 0;
	list->space = 0;
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->dot = 0;
	list->precision = 0;
	list->format = 0;
}
