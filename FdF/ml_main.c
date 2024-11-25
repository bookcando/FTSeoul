/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:20:57 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 19:07:46 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf.h"

static int	on_destroy(void)
{
	exit (0);
}

void	get_scale(t_vars *vars)
{
	int	scale;

	if (vars->width == 0 || vars-> height == 0)
		return ;
	scale = 0;
	if ((SCREEN_WIDTH / vars->width) > (SCREEN_HEIGHT / vars->height))
		scale = SCREEN_HEIGHT / 2 / vars->height;
	else
		scale = SCREEN_WIDTH / 2 / vars->width;
	if (scale < 1)
		scale = 1;
	vars->scale = scale;
}

static void	ml_mlx_init(t_vars *ml_mlx)
{
	ml_mlx->mlx = mlx_init();
	ml_mlx->win = mlx_new_window(ml_mlx->mlx, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "minsulee_fdf");
	ml_mlx->data.img = mlx_new_image(ml_mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	ml_mlx->data.addr = mlx_get_data_addr(ml_mlx->data.img, \
		&(ml_mlx->data.bits_per_pixel), &(ml_mlx->data.line_length), \
		&(ml_mlx->data.endian));
	ml_mlx->center_x = SCREEN_WIDTH / 2;
	ml_mlx->center_y = SCREEN_HEIGHT / 2;
	ml_mlx->width = 0;
	ml_mlx->height = 0;
	ml_mlx->map_xyzc = 0;
	ml_mlx->scale = 1;
}

int	main(int argc, char **argv)
{
	t_vars	ml_mlx;
	double	*map_xyzc;

	if (argc != 2)
		return (0);
	ml_mlx_init(&ml_mlx);
	map_xyzc = get_map_xyzc(&ml_mlx, argv[1]);
	ml_mlx.map_xyzc = map_xyzc;
	get_scale(&ml_mlx);
	map_draw_zc(&ml_mlx, map_xyzc);
	mlx_hook(ml_mlx.win, 2, 1L << 0, key_hook, &ml_mlx);
	mlx_hook(ml_mlx.win, 17, 0, on_destroy, &ml_mlx);
	mlx_put_image_to_window(ml_mlx.mlx, ml_mlx.win, ml_mlx.data.img, 0, 0);
	mlx_loop(ml_mlx.mlx);
}
