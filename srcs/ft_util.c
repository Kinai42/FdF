/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 02:38:52 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/22 04:29:12 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

int		ft_height_map(char *av)
{
	char	c;
	int		fd;
	int		height;

	height = 0;
	if (!(fd = open(av, O_RDONLY)))
		return (0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			height++;
	}
	return (height);
}

void	get_colors_x(t_fdf *fdf, int h, int w)
{
	if (w < fdf->width - 1 && fdf->tab[h][w + 1] != fdf->tab[h][w])
		draw_line(fdf, 102, 0, 0);
	else if (fdf->tab[h][w] == 0)
		draw_line(fdf, 255, 102, 102);
	else if (fdf->tab[h][w] != 0)
		draw_line(fdf, 255, 0, 0);
}

int		draw_line_menu(t_fdf *fdf, int r, int g, int b)
{
	double		i;
	double		dist;
	double		ratio;
	int			x;
	int			y;

	i = 0;
	dist = sqrt(pow((fdf->d_x - fdf->o_x), 2) + pow((fdf->d_y - fdf->o_y), 2));
	while (i < dist)
	{
		ratio = i / dist;
		x = fdf->o_x + (fdf->d_x - fdf->o_x) * ratio;
		y = fdf->o_y + (fdf->d_y - fdf->o_y) * ratio;
		if (x >= 0 && x < SCREEN_X && y >= 0 && y < SCREEN_Y)
			pixel_put(fdf->pixel, x, y, (b << 16) + (g << 8) + (r));
		i += 0.1;
	}
	return (0);
}

void	get_colors_y(t_fdf *fdf, int h, int w)
{
	if (h < fdf->height - 1 && fdf->tab[h + 1][w] != fdf->tab[h][w])
		draw_line(fdf, 102, 0, 0);
	else if (fdf->tab[h][w] != 0)
		draw_line(fdf, 255, 0, 0);
	else if (fdf->tab[h][w] == 0)
		draw_line(fdf, 255, 102, 102);
}

int		leave_window(void)
{
	exit(-1);
	return (0);
}
