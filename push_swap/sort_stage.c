/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:11:15 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/31 15:45:33 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	*get_stage_string(t_stack **stack, int elements, int stages)
{
	char	*section_string;
	int		section_length;

	section_string = (char *)malloc(2 * sizeof(char));
	if (section_string == 0)
		ml_exit(stack, 0);
	section_string[1] = 0;
	if (stages % 2 == 0)
		section_string[0] = 'a';
	else
		section_string[0] = 'd';
	section_length = 1;
	while ((elements / section_length > 9) || \
	((elements / section_length >= 9) && (elements % section_length)))
	{
		section_string = mirror(section_string);
		section_length *= 3;
	}
	return (section_string);
}

int	stage_first(t_stack **from, t_stack **to, int elements, char *string)
{
	int	pass;
	int	index;
	int	length;

	length = ft_strlen(string);
	index = 0;
	while (length > 0)
	{
		pass = elements / length;
		elements = elements - pass;
		if (string[length - 1] == 'd')
			right_init(from, to, pass);
		else
			reverse_init(from, to, pass);
		index++;
		length--;
		if ((*from) == 0)
			break ;
	}
	return (index);
}

int	stage_even(t_stack **to, t_stack **from, int index, char *string)
{
	int	length;

	length = pass_again(index);
	index = 0;
	while (index < length)
	{
		if (string[index] == 'a')
			send_reversed_right(from, to, 'b', 'a');
		else if (string[index] == 'd')
			send_right_reversed(from, to, 'b', 'a');
		index++;
	}
	index = 0;
	length = ft_strlen(string);
	while (index < length)
	{
		if (string[length - index - 1] == 'd')
			right_m(from, to, 'b', 'a');
		else if (string[length - index - 1] == 'a')
			reverse_m(from, to, 'b', 'a');
		index++;
		if ((*from) == 0)
			break ;
	}
	return (index);
}

int	stage_odd(t_stack **from, t_stack **to, int index, char *string)
{
	int	length;

	length = pass_again(index);
	index = 0;
	while (index < length)
	{
		if (string[index] == 'a')
			send_reversed_right(from, to, 'a', 'b');
		else if (string[index] == 'd')
			send_right_reversed(from, to, 'a', 'b');
		index++;
	}
	index = 0;
	length = ft_strlen(string);
	while (index < length)
	{
		if (string[length - index - 1] == 'd')
			right_m(from, to, 'a', 'b');
		else if (string[length - index - 1] == 'a')
			reverse_m(from, to, 'a', 'b');
		index++;
		if ((*from) == 0)
			break ;
	}
	return (index);
}

int	stage_last(t_stack **to, t_stack **from, int index, char *string)
{
	int	length;

	length = pass_again(index);
	index = 0;
	while (index < length)
	{
		if (string[index] == 'a')
			send_reversed_right(from, to, 'b', 'a');
		else if (string[index] == 'd')
			send_right_reversed(from, to, 'b', 'a');
		index++;
	}
	while ((*from)->value < (*from)->down->value)
		stack_rotate(from, 'b');
	index = 0;
	length = ft_strlen(string);
	while ((index < length) && ((*from != 0)))
	{
		if (string[length - index - 1] == 'd')
			right_m(from, to, 'b', 'a');
		else if (string[length - index - 1] == 'a')
			reverse_m(from, to, 'b', 'a');
		index++;
	}
	return (index);
}
