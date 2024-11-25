/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:25:58 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 14:16:23 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	helper_c(t_stack **from, t_stack **to)
{
	if ((*from)->value < (*to)->up->value && \
	((*from)->value <= (*from)->up->value))
		return (1);
	else if (((*from)->up->value <= (*from)->value) && \
	((*from)->up->value < (*to)->up->value))
		return (2);
	return (4);
}

static int	helper_d(t_stack **from, t_stack **to)
{
	int	index;

	index = 0;
	index += stack_value_compare((*from), (*to), 1, 0);
	index += stack_value_compare((*from)->up, (*to), 2, 0);
	index += stack_value_compare((*to)->up, (*to), 4, 0);
	return (index);
}

static int	find_smallest_m(t_stack **from, t_stack **to)
{
	int	index;

	if ((*from) == 0)
		return (stack_value_compare((*to)->up, (*to), 4, 0));
	if ((*to) == 0)
		return (stack_value_compare((*from)->up, (*from), 1, 2));
	if ((*to)->value == (*to)->up->value)
		return (stack_value_compare((*from)->up, (*from), 1, 2));
	index = helper_d(from, to);
	if (index == 3)
		return (stack_value_compare((*from), (*from)->up, 2, 1));
	else if (index == 5)
		return (stack_value_compare((*to)->up, (*from), 1, 4));
	else if (index == 6)
		return (stack_value_compare((*from)->up, (*to)->up, 4, 2));
	else if (index == 7)
		return (helper_c(from, to));
	else
		return (index);
}

static int	find_smallest_m2(t_stack **from, t_stack **to)
{
	if ((*from) == 0)
		return (0);
	if ((*to) == 0)
		return (stack_value_compare((*from)->up, (*from), 1, 2));
	if ((*to)->value == (*to)->up->value)
		return (stack_value_compare((*from)->up, (*from), 1, 2));
	return (helper_c(from, to));
}

int	reverse_m(t_stack **from, t_stack **to, char f, char t)
{
	int	index;

	index = find_smallest_m2(from, to);
	while (index)
	{
		if (index == 1)
		{
			stack_push(from, to, f, t);
		}
		else if (index == 2)
		{
			if ((*from)->up != (*from))
				stack_rrotate(from, f);
			stack_push(from, to, f, t);
		}
		else if (index == 4)
		{
			if ((*to)->up != (*to))
				stack_rrotate(to, t);
		}
		index = find_smallest_m(from, to);
	}
	return (0);
}
