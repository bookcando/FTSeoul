/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:15:20 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 14:16:41 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	stack_pull_from(t_stack *element, t_stack **from)
{
	if ((*from) == (*from)->up)
		(*from) = 0;
	else
	{
		stack_connect_elements(element->up, element->down);
		(*from) = (*from)->down;
	}
}

static void	stack_push_to(t_stack *element, t_stack **to)
{
	if ((*to) == 0)
	{
		stack_connect_elements(element, element);
		(*to) = element;
	}
	else
	{
		stack_connect_elements((*to)->up, element);
		stack_connect_elements(element, (*to));
		(*to) = element;
	}
}

void	stack_push(t_stack **from, t_stack **to, char f, char t)
{
	t_stack	*element;

	element = (*from);
	if (element == 0)
		return ;
	stack_pull_from(element, from);
	stack_push_to(element, to);
	if (t == 'a')
		instruction_add(4);
	else if (f == 'a')
		instruction_add(8);
}

void	stack_rotate(t_stack **stack, char c)
{
	if (*stack == 0)
		return ;
	(*stack) = (*stack)->down;
	if (c == 'a')
		instruction_add(16);
	else if (c == 'b')
		instruction_add(32);
}

void	stack_rrotate(t_stack **stack, char c)
{
	if (*stack == 0)
		return ;
	(*stack) = (*stack)->up;
	if (c == 'a')
		instruction_add(64);
	else if (c == 'b')
		instruction_add(128);
}
