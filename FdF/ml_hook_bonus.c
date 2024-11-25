/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:32:15 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/24 18:50:13 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	if (button == 4)
		vars->scale_z += 1;
	else if (button == 5)
		vars->scale_z -= 1;
	else
		return (0);
	if (vars->scale_z < 1)
		vars->scale_z = 1;
	ml_mlx_clear_window(vars);
	map_draw(vars, vars->map_xyzc);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}

static int	key_hook_rotate(int key, t_vars *vars)
{
	if (key == 30)
		vars->rotate_x -= (M_PI / 60);
	else if (key == 33)
		vars->rotate_x += (M_PI / 60);
	else if (key == 39)
		vars->rotate_y -= (M_PI / 60);
	else if (key == 41)
		vars->rotate_y += (M_PI / 60);
	else if (key == 44)
		vars->rotate_z += (M_PI / 60);
	else if (key == 47)
		vars->rotate_z -= (M_PI / 60);
	else
		return (0);
	return (1);
}

static int	key_hook_move(int key, t_vars *vars)
{
	if (key == 2)
		vars->move.x -= 2;
	else if (key == 0)
		vars->move.x += 2;
	else if (key == 1)
		vars->move.y -= 2;
	else if (key == 13)
		vars->move.y += 2;
	else if (key == 6)
		vars->move.z += 2;
	else if (key == 7)
		vars->move.z -= 2;
	else
		return (0);
	return (1);
}

static int	key_hook_scale(int key, t_vars *vars)
{
	if (key == 24)
		vars->scale *= 2;
	else if (key == 27)
		vars->scale /= 2;
	else
		return (0);
	if (vars->scale < 1)
		vars->scale = 1;
	return (1);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		exit(0);
	else if (key_hook_move(key, vars) == 0 && key_hook_rotate(key, vars) == 0 \
	&& key_hook_scale(key, vars) == 0)
		return (0);
	ml_mlx_clear_window(vars);
	map_draw(vars, vars->map_xyzc);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (1);
}
