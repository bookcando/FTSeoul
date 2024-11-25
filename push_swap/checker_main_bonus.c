/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:49:19 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 14:58:44 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	main(int argc, const char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = 0;
	stack_b = 0;
	ml_integer_parser(&stack_a, argc, argv);
	stack_initial_connect(&stack_a);
	if (check_redundancy(&stack_a))
		ml_exit(&stack_a, &stack_b);
	ml_inst_parser(&stack_a, &stack_b);
	if (stack_b != 0)
		write(1, "KO\n", 3);
	else if (check_sorted(&stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stacks(&stack_a, &stack_b));
}
