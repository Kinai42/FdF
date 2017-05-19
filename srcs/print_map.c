/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:58:01 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/19 07:01:16 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void	coord(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->origin_x = ((SCREEN_X / 2) - (fdf->width / 2)) + 150;
	fdf->origin_y = 50;
}

int		print_line_x(t_fdf *fdf)
{
	int		h;
	int		w;
	int		pas;

	h = -1;
	pas = fdf->width;
	fdf->height > fdf->width ? pas = fdf->height : 0;
	while (++h < fdf->height)
	{
		w = 0;
		fdf->o_x = fdf->origin_x - (475 / pas * h);
		fdf->o_y = fdf->origin_y + (399 / pas * h) -
			(fdf->zoom * fdf->tab[h][w]);
		while (w < fdf->width - 1)
		{
			fdf->d_x = fdf->o_x + 475 / pas;
			fdf->d_y = (fdf->o_y + 399 / pas) -
				(fdf->zoom * (fdf->tab[h][w + 1] - fdf->tab[h][w]));
			get_colors_x(fdf, h, w);
			fdf->o_x = fdf->d_x;
			fdf->o_y = fdf->d_y;
			w++;
		}
	}
	return (0);
}

int		print_line_y(t_fdf *fdf)
{
	int		h;
	int		w;
	int		pas;

	w = -1;
	pas = fdf->width;
	fdf->height > fdf->width ? pas = fdf->height : 0;
	while (++w < fdf->width)
	{
		h = 0;
		fdf->o_x = fdf->origin_x + (475 / pas * w);
		fdf->o_y = fdf->origin_y + (399 / pas * w) -
			(fdf->zoom * fdf->tab[h][w]);
		while (h < fdf->height - 1)
		{
			fdf->d_x = fdf->o_x - 475 / pas;
			fdf->d_y = fdf->o_y + 399 / pas -
				(fdf->zoom * (fdf->tab[h + 1][w] - fdf->tab[h][w]));
			get_colors_y(fdf, h, w);
			fdf->o_x = fdf->d_x;
			fdf->o_y = fdf->d_y;
			h++;
		}
	}
	return (0);
}

int		draw_line(t_fdf *fdf, int r, int g, int b)
{
	double		i;
	double		distance;
	double		ratio;
	int			x;
	int			y;

	i = 0;
	distance = sqrt(pow((fdf->d_x - fdf->o_x), 2) +
			pow((fdf->d_y - fdf->o_y), 2));
	while (i < distance)
	{
		ratio = i / distance;
		x = fdf->o_x + (fdf->d_x - fdf->o_x) * ratio;
		y = fdf->o_y + (fdf->d_y - fdf->o_y) * ratio;
		if (X >= 350 && X < SCREEN_X && Y >= 0 && Y < SCREEN_Y)
			pixel_put(fdf->pixel, x, y, (b << 16) + (g << 8) + (r));
		i += 0.1;
	}
	return (0);
}

void	pixel_put(char *pixel, int x, int y, int color)
{
	pixel += x * 4 + y * (4 * SCREEN_X);
	pixel[0] = color >> 16 & 0xff;
	pixel[1] = color >> 8 & 0xff;
	pixel[2] = color & 0xff;
}
