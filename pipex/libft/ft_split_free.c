/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:03:44 by minsulee          #+#    #+#             */
/*   Updated: 2022/12/21 13:03:51 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char **string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		free(string[index]);
		string[index] = 0;
		index++;
	}
	free(string);
	string = 0;
}
