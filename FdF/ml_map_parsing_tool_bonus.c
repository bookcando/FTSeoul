/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_map_parsing_tool_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:37:40 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/24 18:47:55 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

static int	map_width(char *line)
{
	int	count;

	count = 0;
	while (*line && *line != '\n')
	{
		while (*line == ' ')
			line++;
		if (*line != ' ' && *line != '\n' && *line)
		{
			count++;
			while (*line != ' ' && *line != '\n' && *line)
				line++;
		}
	}
	return (count);
}

static int	ml_atoi(char *string)
{
	int		sign;
	ssize_t	num;

	num = 0;
	sign = 1;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		string++;
		if (*string == '-' || *string == '+')
			exit(0);
	}
	while (*string && *string != ' ' && *string != ',')
	{
		if (*string <= '9' && *string >= '0')
			num = num * 10 + (*string - '0');
		else if (!(*string == 0 || *string == '\n' || *string == ','))
			exit(0);
		if (num > 2147483648 || ((sign == 1) && num > 2147483647))
			exit(0);
		string++;
	}
	return (sign * (int)num);
}

static int	ml_atohex(char *string)
{
	ssize_t	num;

	num = 0;
	if (!(*string == '0' && (*(string + 1) == 'x' || *(string + 1) == 'X')))
		exit(0);
	string += 2;
	while (*string && *string != ' ')
	{
		if (*string <= '9' && *string >= '0')
			num = num * 16 + (*string - '0');
		else if (*string <= 'F' && *string >= 'A')
			num = num * 16 + (*string - 'A' + 10);
		else if (*string <= 'f' && *string >= 'a')
			num = num * 16 + (*string - 'a' + 10);
		else if (!(*string == 0 || *string == '\n'))
			exit(0);
		if (num > 2147483648)
			exit(0);
		string++;
	}
	return ((int)num);
}

static void	map_concat_help(char *line, int *ret_map, int index, int index_max)
{
	while (index < index_max)
	{
		while (*line == ' ')
			line++;
		if (*line && *line != ' ' && *line != '\n')
		{
			ret_map[index * 2 + 0] = ml_atoi(line);
			ret_map[index * 2 + 1] = 0x00FFFFFF;
			while (*line && *line != ' ' && *line != '\n')
			{
				if (*line == ',')
				ret_map[index * 2 + 1] = ml_atohex(line + 1);
				line++;
			}
		}
		index++;
	}
}

int	*map_concat(char *line, int *pre_map, int *width, int *height)
{
	int	*ret_map;
	int	index;
	int	index_max;

	if (*width == 0)
		(*width) = map_width(line);
	if ((*width) != map_width(line))
		exit(0);
	ret_map = (int *)ml_malloc(sizeof(int) * ((*width) * ((*height) + 1) * 2));
	index = 0;
	index_max = (*width) * (*height);
	while (index < index_max)
	{
		ret_map[index * 2 + 0] = pre_map[index * 2 + 0];
		ret_map[index * 2 + 1] = pre_map[index * 2 + 1];
		index++;
	}
	free(pre_map);
	(*height)++;
	map_concat_help(line, ret_map, index, ((*height) * (*width)));
	return (ret_map);
}
