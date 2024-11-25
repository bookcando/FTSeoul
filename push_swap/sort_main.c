/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:18:21 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 14:58:43 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ml_merge_sort(t_stack **stack_a, t_stack **stack_b, int num_args)
{
	int		section_length;
	int		stage;
	int		index;
	char	*section_string;

	section_length = 3;
	stage = 1;
	while (((num_args) / section_length > 9) || \
	(((num_args) / section_length >= 9) && ((num_args) % section_length)))
	{
		section_length *= 3;
		stage++;
	}
	section_string = get_stage_string(stack_a, num_args, stage);
	stage = (stage / 2);
	index = stage_first(stack_a, stack_b, num_args, section_string);
	while (stage--)
	{
		index = stage_even(stack_a, stack_b, index, section_string);
		section_string = mirror_break(section_string);
		index = stage_odd(stack_a, stack_b, index, section_string);
		section_string = mirror_break(section_string);
	}
	index = stage_last(stack_a, stack_b, index, "aad");
	free(section_string);
}

int	main(int argc, const char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = 0;
	stack_b = 0;
	ml_integer_parser(&stack_a, argc, argv);
	argc = stack_count(&stack_a);
	if (argc < 1)
		return (0);
	stack_initial_connect(&stack_a);
	if (check_redundancy(&stack_a) == -1)
		ml_exit(&stack_a, &stack_b);
	if (check_sorted(&stack_a))
		return (free_stacks(&stack_a, &stack_b));
	if (argc < 10)
		small_sort(&stack_a, &stack_b, argc);
	else
		ml_merge_sort(&stack_a, &stack_b, argc);
	instruction_add(0);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
