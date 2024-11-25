/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:46:32 by minsulee          #+#    #+#             */
/*   Updated: 2022/10/30 14:16:50 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static char	*mirror_helper(char **string, int length)
{
	int		index_1;
	int		index_2;
	char	*retstr;

	retstr = *string;
	index_1 = 0;
	index_2 = length * 2;
	while (index_1 < length)
	{
		if (retstr[index_2 + index_1] == 'a')
		{
			retstr[length - index_1 - 1] = 'd';
			retstr[index_2 - index_1 - 1] = 'd';
		}
		else
		{
			retstr[length - index_1 - 1] = 'a';
			retstr[index_2 - index_1 - 1] = 'a';
		}
		index_1++;
	}
	return (retstr);
}

char	*mirror(char *string)
{
	int		length;
	char	*retstr;

	length = ft_strlen(string);
	retstr = (char *)malloc((length * 3 + 1) * sizeof(char));
	if (retstr == 0)
		exit (-1);
	retstr[length * 3] = 0;
	ft_strcpy_nonzero(string, &(retstr[length * 2]));
	free(string);
	mirror_helper(&retstr, length);
	return (retstr);
}

char	*mirror_break(char *string)
{
	int		length;
	char	*retstr;

	length = ft_strlen(string) / 3;
	retstr = (char *)malloc((length + 1) * sizeof(char));
	if (retstr == 0)
		return (0);
	retstr[length] = 0;
	ft_strcpy_nonzero(&(string[length * 2]), retstr);
	free(string);
	return (retstr);
}

int	pass_again(int input)
{
	int	power;

	if (input <= 2)
		return (0);
	power = 1;
	while (!(power < input && input <= power * 3))
		power = power * 3;
	power = power - (power * 3 - input);
	if (power < 0)
		return (0);
	return (power);
}
