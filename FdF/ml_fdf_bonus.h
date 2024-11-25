/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_fdf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:43:39 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 20:52:05 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ML_FDF_BONUS_H
# define ML_FDF_BONUS_H
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_posv
{
	double		x;
	double		y;
	double		z;
	double		c;
}				t_posv;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	struct s_data	data;
	double			rotate_x;
	double			rotate_y;
	double			rotate_z;
	int				width;
	int				height;
	int				scale;
	int				scale_z;
	double			center_x;
	double			center_y;
	double			*map_xyzc;
	t_posv			move;
}				t_vars;

size_t	ft_strlen(char *string);
int		ml_abs(int a);
void	*ml_malloc(size_t size);
void	ml_mlx_map_line(t_vars *vars, t_posv a, t_posv b, double *map_zc);
void	ml_mlx_put_pixel(t_data *data, int x, int y, int color);
void	ml_mlx_clear_window(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		key_hook(int key, t_vars *vars);
double	*get_map_xyzc(t_vars *vars, char *input);
int		*map_concat(char *line, int *pre_map, int *width, int *height);
char	*get_next_line(int fd);
void	map_draw(t_vars *vars, double *map);
void	map_draw_zc(t_vars *vars, double *map_3d);
void	isometric_projection(t_vars *vars, t_posv *pos);
#endif