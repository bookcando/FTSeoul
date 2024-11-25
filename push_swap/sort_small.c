/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:51:02 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 14:40:56 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->down->value)
		stack_swap(a, 'a');
	return (0);
}

static int	sort_3(t_stack **a)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = (*a)->value;
	e2 = (*a)->down->value;
	e3 = (*a)->down->down->value;
	if (e3 > e1 && e1 > e2)
		stack_swap(a, 'a');
	else if (e2 > e1 && e1 > e3)
		stack_rrotate(a, 'a');
	else if (e1 > e3 && e3 > e2)
		stack_rotate(a, 'a');
	else if (e2 > e3 && e3 > e1)
		stack_rrotate(a, 'a');
	else if (e1 > e2 && e2 > e3)
		stack_swap(a, 'a');
	else
		return (0);
	return (sort_3(a));
}

int	small_sort(t_stack **from, t_stack **to, int count)
{
	int	index;

	if (count == 2)
		sort_2(from);
	while (count >= 4)
	{
		index = smallest_first(from, count);
		if (index == 99)
			return (0);
		if (index < 0)
			ml_for(stack_rrotate, from, 'a', (-1) * index);
		if (index > 0)
			ml_for(stack_rotate, from, 'a', index - 1);
		if (index >= 1)
			stack_swap(from, 'a');
		stack_push(from, to, 'a', 'b');
		count--;
	}
	sort_3(from);
	while ((*to))
		stack_push(to, from, 'b', 'a');
	return (0);
}
