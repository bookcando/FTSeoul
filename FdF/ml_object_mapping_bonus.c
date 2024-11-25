/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_object_mapping_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:00:12 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 20:28:08 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

static void	map_rotate_z(t_vars *vars, double *map)
{
	int		x;
	int		y;
	t_posv	pos;

	if (fabs(vars->rotate_z) >= 2 * M_PI)
		vars->rotate_z = 0;
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			pos.x = map[(y * vars->width + x) * 4 + 0];
			pos.y = map[(y * vars->width + x) * 4 + 1];
			map[(y * vars->width + x) * 4 + 0] \
			= pos.y * sin(vars->rotate_z) + pos.x * cos(vars->rotate_z);
			map[(y * vars->width + x) * 4 + 1] \
			= pos.y * cos(vars->rotate_z) - pos.x * sin(vars->rotate_z);
			x++;
		}
		y++;
	}
}

static void	map_rotate_y(t_vars *vars, double *map)
{
	int		x;
	int		y;
	t_posv	pos;

	if (fabs(vars->rotate_y) >= 2 * M_PI)
		vars->rotate_y = 0;
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			pos.x = map[(y * vars->width + x) * 4 + 0];
			pos.z = map[(y * vars->width + x) * 4 + 2];
			map[(y * vars->width + x) * 4 + 0] \
			= pos.x * cos(vars->rotate_y) - pos.z * sin(vars->rotate_y);
			map[(y * vars->width + x) * 4 + 2] \
			= pos.x * sin(vars->rotate_y) + pos.z * cos(vars->rotate_y);
			x++;
		}
		y++;
	}
}

static void	map_rotate_x(t_vars *vars, double *map)
{
	int		x;
	int		y;
	t_posv	pos;

	if (fabs(vars->rotate_x) >= 2 * M_PI)
		vars->rotate_x = 0;
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			pos.y = map[(y * vars->width + x) * 4 + 1];
			pos.z = map[(y * vars->width + x) * 4 + 2];
			map[(y * vars->width + x) * 4 + 1] \
			= pos.y * cos(vars->rotate_x) + pos.z * sin(vars->rotate_x);
			map[(y * vars->width + x) * 4 + 2] \
			= pos.z * cos(vars->rotate_x) - pos.y * sin(vars->rotate_x);
			x++;
		}
		y++;
	}
}

static void	map_move(t_vars *vars, double *map)
{
	int		x;
	int		y;
	t_posv	pos;

	pos.x = vars->move.x;
	pos.y = vars->move.y;
	pos.z = vars->move.z;
	if (pos.x == 0 && pos.y == 0 && pos.z == 0)
		return ;
	vars->move.x = 0;
	vars->move.y = 0;
	vars->move.z = 0;
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			map[(y * vars->width + x) * 4 + 0] += pos.x;
			map[(y * vars->width + x) * 4 + 1] += pos.y;
			map[(y * vars->width + x) * 4 + 2] += pos.z;
			x++;
		}
		y++;
	}
}

void	map_draw(t_vars *vars, double *map)
{
	double	*temp_map_xyzc;
	int		index;

	map_move(vars, map);
	index = 0;
	temp_map_xyzc = (double *)ml_malloc(sizeof(double) \
	* (vars->width * vars->height * 4));
	while (index < vars->width * vars->height)
	{
		temp_map_xyzc[index * 4 + 0] = map[index * 4 + 0];
		temp_map_xyzc[index * 4 + 1] = map[index * 4 + 1];
		temp_map_xyzc[index * 4 + 2] = (map[index * 4 + 2] / vars->scale_z);
		temp_map_xyzc[index * 4 + 3] = map[index * 4 + 3];
		index++;
	}
	map_rotate_x(vars, temp_map_xyzc);
	map_rotate_y(vars, temp_map_xyzc);
	map_rotate_z(vars, temp_map_xyzc);
	map_draw_zc(vars, temp_map_xyzc);
	free(temp_map_xyzc);
}
