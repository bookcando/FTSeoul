/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_drawing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:22 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/24 19:34:18 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

static int	get_inc(t_posv a, t_posv b, t_posv *pos_inc)
{
	int	index;

	index = 0;
	if (fabs(b.y - a.y) > fabs(b.x - a.x))
	{
		index = ml_abs(b.y - a.y);
		if (b.y > a.y)
			pos_inc->y = 1;
		else
			pos_inc->y = -1;
		pos_inc->x = (b.x - a.x) / (double)index;
	}
	else
	{
		index = ml_abs(b.x - a.x);
		if (b.x > a.x)
			pos_inc->x = 1;
		else
			pos_inc->x = -1;
		pos_inc->y = (b.y - a.y) / (double)index;
	}
	pos_inc->z = (b.z - a.z) / (double)index;
	return (index);
}

static void	get_color_cur(t_posv *color, t_posv pos)
{
	color->x = (int)(pos.c / 65536) % 256;
	color->y = (int)(pos.c / 256) % 256;
	color->z = (int)(pos.c) % 256;
}

static void	get_color_inc(t_posv *color_inc, t_posv a, t_posv b, int index)
{
	color_inc->x = (((((int)(b.c)) >> 16) % 256) \
	- ((((int)(a.c)) >> 16) % 256)) / ((double)index);
	color_inc->y = (((((int)(b.c)) >> 8) % 256) \
	- ((((int)(a.c)) >> 8) % 256)) / ((double)index);
	color_inc->z = (((((int)(b.c))) % 256) \
	- ((((int)(a.c))) % 256)) / ((double)index);
}

static void	add_inc(t_posv *origin, t_posv *inc)
{
	origin->x = origin->x + inc->x;
	origin->y = origin->y + inc->y;
	origin->z = origin->z + inc->z;
}

void	ml_mlx_map_line(t_vars *vars, t_posv a, t_posv b, double *map_zc)
{
	t_posv	pos_inc;
	t_posv	color;
	t_posv	color_inc;
	int		index;

	index = get_inc(a, b, &pos_inc);
	get_color_inc(&color_inc, a, b, index);
	get_color_cur(&color, a);
	while (index-- >= 0)
	{
		if (!(a.x < 0 || a.y < 0 \
		|| a.x > (SCREEN_WIDTH - 1) || a.y > (SCREEN_HEIGHT - 1)))
		{
			if (map_zc[(int)(a.y + 0.5) *SCREEN_WIDTH \
			+ (int)(a.x + 0.5)] <= a.z)
			{
				ml_mlx_put_pixel(&vars->data, \
				(int)(a.x + 0.5), (int)(a.y + 0.5), \
				((int)color.x * 65536 + (int)color.y * 256 + (int)color.z));
				map_zc[(int)(a.y + 0.5) *SCREEN_WIDTH + (int)(a.x + 0.5)] = a.z;
			}
		}
		add_inc(&color, &color_inc);
		add_inc(&a, &pos_inc);
	}
}
