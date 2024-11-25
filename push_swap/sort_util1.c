/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:13:54 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:38:09 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ml_for(void (*func)(t_stack **, char), t_stack **stack, char c, int t)
{
	while (t)
	{
		func(stack, c);
		t--;
	}
}

int	stack_value_compare(t_stack *a, t_stack *b, int ia, int ib)
{
	if (b == 0)
		return (ia);
	if (a == 0)
		return (ib);
	if (a->value >= b->value)
		return (ia);
	else
		return (ib);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*next;

	if ((*stack)->up)
		((*stack)->up)->down = 0;
	while (*stack != 0)
	{
		next = (*stack)->down;
		free(*stack);
		*stack = next;
	}
}

int	free_stacks(t_stack **a, t_stack **b)
{
	if (a != 0)
		if ((*a) != 0)
			free_stack(a);
	if (b != 0)
		if ((*b) != 0)
			free_stack(b);
	return (0);
}

int	action_by_index(t_stack **from, t_stack **to, int count, int index)
{
	int	sign;

	sign = ((count + 1) % 2);
	if (index == 99)
		return (0);
	if (index < 0)
		ml_for(stack_rrotate, from, 'a', (-1) * index);
	if (index > 0)
		ml_for(stack_rotate, from, 'a', index - 1);
	if (index >= 1)
		stack_swap(from, 'a');
	stack_push(from, to, 'a', 'b');
	if (index == 0 && sign == 0)
		stack_rrotate(from, 'a');
	if (index < 0)
		ml_for(stack_rotate, from, 'a', (-1) * index - 1 + sign);
	if (index > 0)
		ml_for(stack_rrotate, from, 'a', index - sign);
	return (0);
}
