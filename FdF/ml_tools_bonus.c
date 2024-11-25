/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:39:54 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 20:32:38 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

void	*ml_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == 0)
		exit(0);
	return (ptr);
}

int	ml_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

size_t	ft_strlen(char *string)
{
	size_t	index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}

void	isometric_projection(t_vars *vars, t_posv *pos)
{
	t_posv	temp;

	temp.x = (pos->x - pos->y) * sqrt(3) / 2.0 \
	* vars->scale + vars->center_x;
	temp.y = (pos->x + pos->y - 2.0 * (pos->z)) / 2.0 \
	* vars->scale + vars->center_y;
	pos->x = temp.x;
	pos->y = temp.y;
}
