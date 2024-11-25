/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_object_zmapping_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:03:12 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 21:04:30 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

static void	get_posv(t_posv *pos, double *map_part)
{
	pos->x = map_part[0];
	pos->y = map_part[1];
	pos->z = map_part[2];
	pos->c = map_part[3];
}

static void	map_draw_dot(t_vars *vars, double *map3d, double *mapz)
{
	t_posv	pos_a;
	t_posv	pos_b;

	if (vars->width == 1 && vars->height == 1)
	{
		get_posv(&pos_a, &map3d[0]);
		get_posv(&pos_b, &map3d[0]);
		isometric_projection(vars, &pos_a);
		isometric_projection(vars, &pos_b);
		ml_mlx_map_line(vars, pos_a, pos_b, mapz);
	}
}

static void	map_draw_x(t_vars *vars, double *map3d, double *mapz)
{
	int		x;
	int		y;
	t_posv	pos_a;
	t_posv	pos_b;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width - 1)
		{
			get_posv(&pos_a, &map3d[(y * vars->width + x + 0) * 4]);
			get_posv(&pos_b, &map3d[(y * vars->width + x + 1) * 4]);
			isometric_projection(vars, &pos_a);
			isometric_projection(vars, &pos_b);
			ml_mlx_map_line(vars, pos_a, pos_b, mapz);
			x++;
		}
		y++;
	}
}

static void	map_draw_y(t_vars *vars, double *map3d, double *mapz)
{
	int		x;
	int		y;
	t_posv	pos_a;
	t_posv	pos_b;

	y = 0;
	while (y < vars->height - 1)
	{
		x = 0;
		while (x < vars->width)
		{
			get_posv(&pos_a, &map3d[((y + 0) * vars->width + x) * 4]);
			get_posv(&pos_b, &map3d[((y + 1) * vars->width + x) * 4]);
			isometric_projection(vars, &pos_a);
			isometric_projection(vars, &pos_b);
			ml_mlx_map_line(vars, pos_a, pos_b, mapz);
			x++;
		}
		y++;
	}
}

void	map_draw_zc(t_vars *vars, double *map_3d)
{
	double	*map_z;
	int		low;
	int		index;
	int		map_size;

	map_size = SCREEN_WIDTH * SCREEN_HEIGHT;
	map_z = (double *)ml_malloc((map_size) * sizeof(double));
	index = 0;
	low = (int)map_3d[2];
	while (index < vars->height * vars->width)
	{
		if (low > map_3d[index * 4 + 2])
			low = (int)map_3d[index * 4 + 2];
		index++;
	}
	low--;
	index = 0;
	while (index < map_size)
		map_z[index++] = low;
	map_draw_x(vars, map_3d, map_z);
	map_draw_y(vars, map_3d, map_z);
	map_draw_dot(vars, map_3d, map_z);
	free(map_z);
}
