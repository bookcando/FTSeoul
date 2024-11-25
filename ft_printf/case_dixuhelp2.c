/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_dixuhelp2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:37:17 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 17:15:25 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_detector(ssize_t num, t_flag *list)
{
	if (list->format == 'i' || list->format == 'd')
	{	
		if (num < 0)
			return (-1);
		else
			return (1);
	}
	else
		return (0);
}

int	numlen_initializer(ssize_t num, t_flag *list)
{
	if (list->format == 'x' || list->format == 'X' || list->format == 'p')
		return (get_numlen_numpart_u(num, 16));
	else if (list->format == 'u')
		return (get_numlen_numpart_u(num, 10));
	else
		return (get_numlen_numpart_s(num, 10));
}

int	get_numlen(ssize_t num, t_flag *list, size_t *numlen, size_t *pzero)
{
	char	sign;

	sign = sign_detector(num, list);
	*numlen = numlen_initializer(num, list);
	*pzero = 0;
	if (list->precision)
		*pzero = max(list->precision, *numlen) - *numlen;
	*numlen = *numlen + *pzero;
	if (list->format == 'x' || list->format == 'X' || list->format == 'p')
		*numlen = rule_px(num, list, *numlen);
	if (num == 0 && list->precision == 0 && list->dot == 1)
		*numlen = 0;
	if (sign)
		if (sign == -1 || list->plus || list->space)
			(*numlen)++;
	return (sign);
}

size_t	rule_px(unsigned int num, t_flag *list, size_t numlen)
{
	if (num == 0 && list->format != 'p')
		list->sharp = 0;
	if (list->format == 'p')
		list->format = 'x';
	if (list->sharp)
	{
		numlen = numlen + 2;
		if (list->dot)
			list->zero = 0;
	}
	return (numlen);
}

int	write_num_pre(size_t numlen, size_t pzero, t_flag *list, char sign)
{
	if (!(list->minus) && !(list->zero))
		if (write_c(max(list->width, numlen) - numlen, ' ') == -1)
			return (-1);
	if (sign && ((list->space || list->plus || sign == -1) \
		&& list->zero && !list->dot))
		if (put_sign(list, sign) == -1)
			return (-1);
	if (list->sharp && (list->format == 'x' || list->format == 'X'))
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		if (write(1, &(list->format), 1) == -1)
			return (-1);
	}
	if (list->zero)
		if (width_filler(numlen, list) == -1)
			return (-1);
	if (sign && ((list->space || list->plus || sign == -1) \
		&& (!list->zero || list->dot)))
		if (put_sign(list, sign) == -1)
			return (-1);
	if (write_c(pzero, '0') == -1)
		return (-1);
	return (0);
}
