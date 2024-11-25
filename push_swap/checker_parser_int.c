/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:33:17 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 17:44:19 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	ml_atoi_helper(const char *string, int sign)
{
	ssize_t	num;

	num = 0;
	if (*string == 0 || *string == ' ')
		return (-1);
	while (*string && (*string != ' '))
	{
		if (!(*string <= '9' && '0' <= *string))
			return (-1);
		num = num * 10 + ((*string) - '0');
		if ((sign == 1 && num >= 2147483648) || \
		(sign == -1 && num > 2147483648))
			return (-1);
		string++;
	}
	return ((int)num);
}

static int	ml_atoi(t_stack **a, const char *string)
{
	ssize_t	num;
	int		sign;
	int		error_sign;

	num = 0;
	error_sign = 0;
	sign = 1;
	while (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		if (*(string + 1) == '-' || (*(string + 1) == '+'))
			error_sign = 1;
		string++;
	}
	num = ml_atoi_helper(string, sign);
	if ((error_sign) || (num == -1))
		ml_exit(a, 0);
	return ((int)num * sign);
}

static int	ml_is_integer(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

void	ml_integer_parser(t_stack **stack, int argc, const char **argv)
{
	int	num;
	int	index_big;
	int	index_small;

	if (argc == 1)
		exit (-1);
	index_big = 1;
	while (index_big < argc)
	{
		index_small = 0;
		while (argv[index_big] != 0)
		{
			while (argv[index_big][index_small] == ' ')
				index_small++;
			if (argv[index_big][index_small] == 0)
				break ;
			num = ml_atoi(stack, (&(argv[index_big][index_small])));
			stack_initial_add(stack, num);
			while (ml_is_integer(argv[index_big][index_small]))
				index_small++;
		}
		index_big++;
	}
}
