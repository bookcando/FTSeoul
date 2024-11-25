/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser_inst_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:18:48 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 17:44:59 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	instruction_add(int inst)
{
	inst = 0;
	return (inst);
}

static int	check_inst_exec_r(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n", 5) == 0)
		stack_rotate(a, 'a');
	else if (ft_strncmp(line, "rb\n", 5) == 0)
		stack_rotate(b, 'b');
	else if (ft_strncmp(line, "rr\n", 5) == 0)
	{
		stack_rotate(b, 'b');
		stack_rotate(a, 'a');
	}
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		stack_rrotate(a, 'a');
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		stack_rrotate(b, 'b');
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
	{
		stack_rrotate(a, 'a');
		stack_rrotate(b, 'b');
	}
	else
	{
		free(line);
		ml_exit(a, b);
	}
	return (0);
}

static int	check_inst_exec(t_stack **a, t_stack **b, char *line)
{
	if (*line == 'r')
		check_inst_exec_r(a, b, line);
	else if (ft_strncmp(line, "sa\n", 5) == 0)
		stack_swap(a, 'a');
	else if (ft_strncmp(line, "sb\n", 5) == 0)
		stack_swap(b, 'b');
	else if (ft_strncmp(line, "ss\n", 5) == 0)
	{
		stack_swap(a, 'a');
		stack_swap(b, 'b');
	}
	else if (ft_strncmp(line, "pa\n", 5) == 0)
		stack_push(b, a, 'b', 'a');
	else if (ft_strncmp(line, "pb\n", 5) == 0)
		stack_push(a, b, 'a', 'b');
	else
	{
		free(line);
		ml_exit(a, b);
	}
	return (0);
}

char	*gnl_simple(t_stack **stack_a, t_stack **stack_b, int fd)
{
	char	*string;
	int		index;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		ml_exit(stack_a, stack_b);
	string = (char *)malloc(8 * sizeof(char));
	if (string == 0)
		ml_exit(stack_a, stack_b);
	index = 0;
	while (index < 8)
		string[index++] = 0;
	index = 0;
	while (index < 7)
	{
		if ((read(fd, &(string[index]), 1) == 0) || \
		(string[index] == 0 || string[index] == '\n'))
			break ;
		index++;
	}
	return (string);
}

void	ml_inst_parser(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	char	flush;

	while (1)
	{
		line = gnl_simple(stack_a, stack_b, 0);
		if (line == 0)
			break ;
		if (*line == 0)
		{
			free(line);
			break ;
		}
		flush = 20;
		if (line[6] != '\n' && line[6] != 0)
		{
			while (flush != 0 && flush != '\n')
				if ((read(0, &(flush), 1) <= 0))
					break ;
		}
		check_inst_exec(stack_a, stack_b, line);
		free(line);
	}
}
