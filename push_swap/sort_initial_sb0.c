/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initial_sb0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:00:02 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:20:12 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	helper_a_smallest(t_stack **from, t_stack **to)
{
	int	index;

	index = 0;
	index += stack_value_compare((*from), (*to), 1, 0);
	index += stack_value_compare((*from)->down, (*to), 2, 0);
	index += stack_value_compare((*from)->up, (*to), 4, 0);
	if (index == 0)
		return (99);
	return (index);
}

static int	find_biggest_first(t_stack **from, t_stack **to)
{
	int	index;

	index = helper_a_smallest(from, to);
	if (index == 3)
		return (stack_value_compare((*from), (*from)->down, 1, 0));
	else if (index == 5)
		return (stack_value_compare((*from), (*from)->up, -1, 0));
	else if (index == 6)
		return (stack_value_compare((*from)->down, (*from)->up, -1, 1));
	else if (index == 7)
		return (three_smallest_first(from));
	else if (index == 1)
		return (0);
	else if (index == 2)
		return (1);
	else if (index == 4)
		return (-1);
	else
		return (99);
}

static int	valid_check_bigger(t_stack **from, t_stack **to, int index)
{
	t_stack	*temp;

	temp = stack_go(from, index);
	return (stack_value_compare(temp, (*to), 1, 0));
}

int	smallest_first(t_stack **stack, int count)
{
	t_stack	*temp_pre;
	t_stack	*temp_now;
	int		sign;
	int		index;

	if (count <= 3)
		return (three_smallest_first(stack));
	index = smallest_first(stack, count - 1);
	temp_pre = stack_go(stack, index);
	sign = 1;
	if (count % 2 == 1)
		sign = -1;
	count = (count / 2) * sign;
	temp_now = stack_go(stack, count);
	return (stack_value_compare(temp_pre, temp_now, count, index));
}

int	smallest_middle(t_stack **from, t_stack **to, int count)
{
	t_stack	*temp_pre;
	t_stack	*temp_now;
	int		index_pre;
	int		index_now;

	if (count <= 3)
		return (find_biggest_first(from, to));
	index_now = count_to_index(count);
	index_pre = smallest_middle(from, to, count - 1);
	if (valid_check_bigger(from, to, index_now))
	{
		temp_now = stack_go(from, index_now);
		if (index_pre == 99)
			return (index_now);
	}
	else
		return (index_pre);
	temp_pre = stack_go(from, index_pre);
	return (stack_value_compare(temp_pre, temp_now, index_now, index_pre));
}
