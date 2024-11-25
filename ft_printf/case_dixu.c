/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_dixu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:03:18 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 17:11:34 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	case_di(int num, t_flag *list)
{
	size_t	numlen;
	size_t	padding_zero;
	char	sign;

	sign = get_numlen(num, list, &numlen, &padding_zero);
	if (write_num_pre(numlen, padding_zero, list, sign) == -1)
		return (-1);
	if (num == 0 && !(list->precision == 0 && list->dot == 1))
	{
		if (write (1, "0", 1) == -1)
			return (-1);
	}
	else
	{
		if (print_num_s(sign, num, 10, "0123456789") == -1)
			return (-1);
	}
	if (list->minus)
		if (write_c(max(list->width, numlen) - numlen, ' ') == -1)
			return (-1);
	return (max(list->width, numlen));
}

ssize_t	case_x(size_t num, t_flag *list)
{
	size_t	numlen;
	size_t	padding_zero;

	get_numlen(num, list, &numlen, &padding_zero);
	if (write_num_pre(numlen, padding_zero, list, 0) == -1)
		return (-1);
	if (num == 0 && numlen != 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
	}
	else if (list->format == 'x')
	{	
		if (print_num_u(num, 16, "0123456789abcdef") == -1)
			return (-1);
	}
	else
		if (print_num_u(num, 16, "0123456789ABCDEF") == -1)
			return (-1);
	if (list->minus)
		if (write_c(max(list->width, numlen) - numlen, ' ') == -1)
			return (-1);
	return (max(list->width, numlen));
}

ssize_t	case_u(size_t num, t_flag *list)
{
	size_t	numlen;
	size_t	padding_zero;

	get_numlen(num, list, &numlen, &padding_zero);
	if (write_num_pre(numlen, padding_zero, list, 0) == -1)
		return (-1);
	if (num == 0 && list->precision == 0 && list->dot == 1)
	{
		if (write(1, "", 0) == -1)
			return (-1);
	}
	else if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
	}
	else
	{
		if (print_num_u(num, 10, "0123456789") == -1)
			return (-1);
	}
	if (list->minus)
		if (write_c(max(list->width, numlen) - numlen, ' ') == -1)
			return (-1);
	return (max(list->width, numlen));
}

size_t	get_numlen_numpart_s(ssize_t num, int base)
{
	size_t	len;

	len = 0;
	while (num)
	{
		num = num / base;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

size_t	get_numlen_numpart_u(size_t num, int base)
{
	size_t	len;

	len = 0;
	while (num)
	{
		num = num / base;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}
