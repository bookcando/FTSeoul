/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack0_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:49:28 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 14:46:48 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_stack	*stack_generate(int input)
{
	t_stack	*element;

	element = (t_stack *)malloc(1 * sizeof(t_stack));
	if (element == 0)
		return (0);
	element->value = input;
	element->down = 0;
	element->up = 0;
	return (element);
}

void	stack_connect_elements(t_stack *upper, t_stack *lower)
{
	upper->down = lower;
	lower->up = upper;
}

void	stack_initial_connect(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->up)
	{
		stack_connect_elements(temp->up, temp);
		temp = temp->up;
	}
	stack_connect_elements(*stack, temp);
	(*stack) = temp;
}

void	stack_initial_add(t_stack **stack, int input)
{
	t_stack	*element;

	element = stack_generate(input);
	if (element == 0)
		ml_exit(stack, 0);
	element->up = *stack;
	(*stack) = element;
}

void	stack_swap(t_stack **stack, char c)
{
	t_stack	*temp_1;
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*temp_4;

	if (*stack == 0)
		return ;
	temp_1 = (*stack)->up;
	temp_a = (*stack);
	temp_b = (*stack)->down;
	temp_4 = (*stack)->down->down;
	stack_connect_elements(temp_1, temp_b);
	stack_connect_elements(temp_a, temp_4);
	stack_connect_elements(temp_b, temp_a);
	if (temp_a->down == temp_a || temp_b->up == temp_b)
		stack_connect_elements(temp_a, temp_b);
	(*stack) = temp_b;
	if (c == 'a')
		instruction_add(1);
	else
		instruction_add(2);
}
