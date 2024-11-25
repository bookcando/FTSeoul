/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_map_parsing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:26:01 by minsulee          #+#    #+#             */
/*   Updated: 2022/11/25 19:51:59 by minsulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ml_fdf_bonus.h"

static int	*map_parse(char *input, int *width, int *height)
{
	int		fd;
	char	*line;
	int		*ret_map;

	fd = open(input, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		exit (0);
	ret_map = (int *)ml_malloc(sizeof(int) * 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
		{
			free(line);
			break ;
		}
		ret_map = map_concat(line, ret_map, width, height);
		free(line);
	}
	close (fd);
	return (ret_map);
}

static void	map_zc2xyzc(t_vars *vars, int *map, double *ret_map)
{
	int		index_x;
	int		index_y;
	double	center_x;
	double	center_y;

	center_x = ((double)vars->width - 1.0) / 2.0;
	center_y = ((double)vars->height - 1.0) / 2.0;
	index_y = 0;
	while (index_y < vars->height)
	{
		index_x = 0;
		while (index_x < vars->width)
		{
			ret_map[(index_y * vars->width + index_x) * 4 + 0] \
			= (double)index_x - center_x;
			ret_map[(index_y * vars->width + index_x) * 4 + 1] \
			= (double)index_y - center_y;
			ret_map[(index_y * vars->width + index_x) * 4 + 2] \
			= map[(index_y * vars->width + index_x) * 2];
			ret_map[(index_y * vars->width + index_x) * 4 + 3] \
			= map[(index_y * vars->width + index_x) * 2 + 1];
			index_x++;
		}
		index_y++;
	}
}

double	*get_map_xyzc(t_vars *vars, char *input)
{
	int		*map;
	double	*ret_map;

	map = map_parse(input, &(vars->width), &(vars->height));
	ret_map = (double *)ml_malloc(sizeof(double) \
	* (vars->width * vars->height * 4));
	map_zc2xyzc(vars, map, ret_map);
	free(map);
	return (ret_map);
}
