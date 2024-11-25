/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:40:31 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 21:27:12 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ml_exit(t_stack **stack_a, t_stack **stack_b)
{
	free_stacks(stack_a, stack_b);
	write(2, "Error\n", 6);
	exit (-1);
}

int	check_redundancy(t_stack **stack)
{
	t_stack	*temp_head;
	t_stack	*temp_iter;
	t_stack	*stack_last;

	if ((*stack) == 0)
		return (0);
	if ((*stack)->value == (*stack)->up->value && \
	((*stack) != (*stack)->up))
		return (-1);
	temp_head = (*stack);
	stack_last = (*stack)->up;
	while (temp_head != stack_last)
	{
		temp_iter = temp_head->down;
		while (temp_iter != stack_last)
		{
			if (temp_head->value == temp_iter->value)
				return (-1);
			temp_iter = temp_iter->down;
		}
		if (temp_head->value == temp_iter->value)
			return (-1);
		temp_head = temp_head->down;
	}
	return (0);
}

int	check_sorted(t_stack **stack)
{
	t_stack	*last;
	t_stack	*index;

	if (*stack == 0 || ((*stack) == (*stack)->up))
		return (1);
	last = (*stack)->up;
	index = (*stack);
	while (index != last)
	{
		if (index->value > index->down->value)
			return (0);
		index = index->down;
	}
	return (1);
}

int	stack_count(t_stack **stack)
{
	t_stack	*temp;
	int		count;

	temp = (*stack);
	if (temp == 0)
		return (0);
	count = 1;
	while (temp->up)
	{
		count++;
		temp = temp->up;
	}
	return (count);
}
