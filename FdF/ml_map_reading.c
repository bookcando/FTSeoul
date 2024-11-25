/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_map_reading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:25:58 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 19:20:34 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf.h"

static void	buffer_pull(char *buffer)
{
	int	index;
	int	temp;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == 0)
		buffer[0] = 0;
	else
	{
		index++;
		temp = 0;
		while (buffer[temp + index])
		{
			buffer[temp] = buffer[temp + index];
			temp++;
		}
		buffer[temp] = 0;
	}
}

static void	string_move(char *dest, char *pre, char *bf)
{
	int	index;

	index = 0;
	while (pre[index])
	{
		dest[index] = pre[index];
		index++;
	}
	dest = &dest[index];
	index = 0;
	while (bf[index])
	{
		dest[index] = bf[index];
		index++;
		if (dest[index - 1] == '\n')
			break ;
	}
	dest[index] = 0;
}

static char	*string_concat(char *pre, char *bf)
{
	int		prelen;
	int		bflen;
	char	*retstr;

	prelen = ft_strlen(pre);
	bflen = 0;
	while (bf[bflen] && bf[bflen] != '\n')
		bflen++;
	if (bf[bflen] == '\n')
		bflen++;
	retstr = (char *)ml_malloc(sizeof(char) * (prelen + bflen + 1));
	string_move(retstr, pre, bf);
	buffer_pull(bf);
	free(pre);
	return (retstr);
}

static char	*gnl_read(int fd, char *string, char *buffer)
{
	int	length;
	int	index;

	while (1)
	{
		length = read(fd, buffer, BUFFER_SIZE);
		buffer[length] = 0;
		if (length == 0 && *string == 0)
		{
			free(string);
			return (0);
		}
		else if (length == 0)
			return (string);
		index = 0;
		while (index < BUFFER_SIZE && buffer[index])
		{
			if (buffer[index] == '\n' || buffer[index] == 0)
				return (string_concat(string, buffer));
			index++;
		}
		string = string_concat(string, buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			index;
	char		*string;

	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		buffer[0] = 0;
		return (0);
	}
	string = (char *)ml_malloc(sizeof(char) * 1);
	string[0] = 0;
	index = 0;
	if (buffer[0] != 0)
	{
		while (index <= BUFFER_SIZE && buffer[index])
		{
			if (buffer[index] == '\n')
				return (string_concat(string, buffer));
			index++;
		}
		string = string_concat(string, buffer);
	}
	return (gnl_read(fd, string, buffer));
}
