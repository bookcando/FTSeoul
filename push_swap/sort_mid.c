/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:25:22 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:44:41 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	send_reversed_right(t_stack **from, t_stack **to, char f, char t)
{
	if (*from == 0)
		return (0);
	if ((*from)->value < (*from)->down->value)
		return (0);
	while ((*from)->value > (*from)->down->value)
	{
		stack_push(from, to, f, t);
	}
	stack_push(from, to, f, t);
	return (1);
}

int	send_right_reversed(t_stack **from, t_stack **to, char f, char t)
{
	if (*from == 0)
		return (0);
	if ((*from)->value > (*from)->down->value)
		return (0);
	while ((*from)->value < (*from)->down->value)
	{
		stack_push(from, to, f, t);
	}
	stack_push(from, to, f, t);
	return (1);
}
