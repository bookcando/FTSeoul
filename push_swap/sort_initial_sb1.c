/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initial_sb1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:45:38 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 14:16:00 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	three_smallest_first(t_stack **stack)
{
	if ((*stack)->value <= (*stack)->up->value && \
	(*stack)->value <= (*stack)->down->value)
		return (0);
	else if ((*stack)->down->value <= (*stack)->up->value && \
	(*stack)->down->value <= (*stack)->value)
		return (1);
	else if ((*stack)->up->value <= (*stack)->value && \
	(*stack)->up->value <= (*stack)->down->value)
		return (-1);
	return (99);
}

int	reverse_init(t_stack **from, t_stack **to, int count)
{
	int	index;

	index = smallest_first(from, count);
	action_by_index(from, to, count, index);
	while (--count)
	{
		if (count == 1)
		{
			if ((*from)->value > (*to)->value)
				index = 0;
		}
		else
			index = smallest_middle(from, to, count);
		action_by_index(from, to, count, index);
	}
	return (0);
}
