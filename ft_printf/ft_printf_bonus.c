/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:13:23 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 18:44:43 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	case_all(const char **input, va_list *arg)
{
	t_flag	list;

	(*input)++;
	if (flag_get(input, &list) == -1)
		return (-1);
	if (list.format == 'i' || list.format == 'd')
		return (case_di(va_arg(*arg, int), &list));
	else if (list.format == 'c')
		return (case_c(va_arg(*arg, int), &list));
	else if (list.format == 's')
		return (case_s(va_arg(*arg, unsigned char *), &list));
	else if (list.format == 'p')
		return (case_p(va_arg(*arg, void *), &list));
	else if (list.format == 'u')
		return (case_u(va_arg(*arg, unsigned int), &list));
	else if (list.format == 'x' || list.format == 'X')
		return (case_x(va_arg(*arg, unsigned int), &list));
	else if (list.format == '%')
		return (case_pct(&list));
	return (-1);
}

int	read_print(const char **input, va_list *arg, int *count)
{
	ssize_t	temp_count;

	temp_count = 0;
	if (**input == '%')
		temp_count = case_all(input, arg);
	else
	{
		if (write(1, *input, 1) == -1)
			return (-1);
		temp_count = 1;
	}
	if (temp_count >= 2147483647)
		return (-1);
	if ((temp_count + (ssize_t)(*count)) >= 2147483647)
		return (-1);
	if (temp_count == -1)
		return (-1);
	return (temp_count + (*count));
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		count;
	int		temp_errorcheck;

	count = 0;
	temp_errorcheck = 0;
	va_start(arg, input);
	while (*input && (count != -1))
	{
		count = read_print(&input, &arg, &count);
		input++;
	}
	va_end(arg);
	return (count);
}
