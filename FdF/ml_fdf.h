/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:43:39 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 20:38:13 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ML_FDF_H
# define ML_FDF_H
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
	int				width;
	int				height;
	double			center_x;
	double			center_y;
	double			*map_xyzc;
	int				scale;
}				t_vars;

size_t	ft_strlen(char *string);
int		ml_abs(int a);
void	*ml_malloc(size_t size);
void	ml_mlx_map_line(t_vars *vars, t_posv a, t_posv b, double *map_zc);
void	ml_mlx_put_pixel(t_data *data, int x, int y, int color);
void	ml_mlx_clear_window(t_vars *vars);
int		key_hook(int key);
double	*get_map_xyzc(t_vars *vars, char *input);
int		*map_concat(char *line, int *pre_map, int *width, int *height);
char	*get_next_line(int fd);
void	map_draw_zc(t_vars *vars, double *map_3d);
void	isometric_projection(t_vars *vars, t_posv *pos);
#endif