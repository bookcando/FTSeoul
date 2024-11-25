/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:10:14 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:30:32 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_go(t_stack **stack, int count)
{
	t_stack	*rstack;

	rstack = (*stack);
	while (count > 0)
	{
		rstack = rstack->down;
		count--;
	}
	while (count < 0)
	{
		rstack = rstack->up;
		count++;
	}
	return (rstack);
}

int	count_to_index(int count)
{
	int	sign;

	if (count <= 1)
		return (0);
	sign = 1;
	if (count % 2 == 1)
		sign = -1;
	return ((count / 2) * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (s == 0)
		return (0);
	count = 0;
	while (*s != 0)
	{
		count++;
		s++;
	}
	return (count);
}

void	ft_strcpy_nonzero(char *src, char *dst)
{
	while (*src)
	{
		(*dst) = (*src);
		src++;
		dst++;
	}
}
