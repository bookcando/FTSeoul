/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:02:27 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:21:53 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	instruction_print(int inst)
{
	if (inst == 1)
		write(1, "sa\n", 3);
	else if (inst == 2)
		write(1, "sb\n", 3);
	else if (inst == 3)
		write(1, "ss\n", 3);
	else if (inst == 4)
		write(1, "pa\n", 3);
	else if (inst == 8)
		write(1, "pb\n", 3);
	else if (inst == 16)
		write(1, "ra\n", 3);
	else if (inst == 32)
		write(1, "rb\n", 3);
	else if (inst == 48)
		write(1, "rr\n", 3);
	else if (inst == 64)
		write(1, "rra\n", 4);
	else if (inst == 128)
		write(1, "rrb\n", 4);
	else if (inst == 192)
		write(1, "rrr\n", 4);
	return (0);
}

int	instruction_add(int cur_inst)
{
	static int	pre_inst;
	int			inst_sum;

	if (pre_inst == 0)
	{
		pre_inst = cur_inst;
		return (0);
	}
	inst_sum = cur_inst + pre_inst;
	pre_inst = 0;
	if (inst_sum == 3)
		instruction_print(3);
	else if (inst_sum == 48)
		instruction_print(48);
	else if (inst_sum == 192)
		instruction_print(192);
	else if (!(inst_sum == 80 || inst_sum == 160 || inst_sum == 12))
	{
		instruction_print(inst_sum - cur_inst);
		pre_inst = cur_inst;
	}
	return (0);
}
