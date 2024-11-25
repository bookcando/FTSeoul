/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_ppct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:33:57 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/03 18:23:53 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	case_p(void *ptr, t_flag *list)
{
	size_t	pointer;

	pointer = (size_t)ptr;
	list->sharp = 1;
	return (case_x(pointer, list));
}

size_t	case_pct(t_flag *list)
{
	if (list->minus)
		if (write(1, "%%", 1) == -1)
			return (-1);
	if (list->width)
	{
		if (list->zero)
		{
			if (write_c(list->width - 1, '0') == -1)
				return (-1);
		}
		else if (write_c(list->width - 1, ' ') == -1)
			return (-1);
	}
	if (!list->minus)
		if (write(1, "%%", 1) == -1)
			return (-1);
	return (max(list->width, 1));
}
