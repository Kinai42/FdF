/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:58:01 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/15 10:44:27 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void	coord(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->origin_x = ((SCREEN_X / 2) - (fdf->width / 2)) + 100;
	fdf->origin_y = 100;
}

int		print_line_x(t_fdf *fdf)
{
	int		h;
	int		w;

	h = -1;
	w = 0;
	while (++h < fdf->height)
	{
		w = 0;
		fdf->o_x = fdf->origin_x - (25 * h);
		fdf->o_y = fdf->origin_y + (20 * h) - (3 * fdf->tab[h][w]);
		while (w < fdf->width - 1)
		{
			fdf->d_x = fdf->o_x + 25;
			if (w == 0)
				fdf->d_y = fdf->o_y + 20 - (3 * (fdf->tab[h][w + 1]));
			else
				fdf->d_y = fdf->o_y + 20 - (3 * (fdf->tab[h][w + 1] - fdf->tab[h][w]));
			draw_line(fdf, 255, 0, 0);
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

	h = 0;
	w = -1;
	while (++w < fdf->width)
	{
		h = 0;
		fdf->o_x = fdf->origin_x + (25 * w);
		fdf->o_y = fdf->origin_y + (20 * w) - (3 * fdf->tab[h][w]);
		while (h < fdf->height - 1)
		{
			fdf->d_x = fdf->o_x - 25;
			fdf->d_y = fdf->o_y + 20 - (3 * (fdf->tab[h + 1][w]));
		if (h == 0 && w > 0)
			fdf->d_y = fdf->o_y + 20 - (3 * (fdf->tab[h + 1][w]));
		else if (h != 0 && w > 0)
				fdf->d_y = fdf->o_y + 20 - (3 * (fdf->tab[h + 1][w] - fdf->tab[h][w]));
			draw_line(fdf, 255, 255, 0);
			fdf->o_x = fdf->d_x;
			fdf->o_y = fdf->d_y;
			h++;
		}
	}
	return (0);
}

int		draw_line(t_fdf *fdf, int r, int g, int b)
{
	int			i;
	int			distance;
	double		ratio;
	int			X;
	int			Y;

	i = 0;
	distance = sqrt(pow((fdf->d_x - fdf->o_x), 2) + pow((fdf->d_y - fdf->o_y), 2));
	while (i < distance)
	{
		ratio = (double)i / (double)distance;
		X = fdf->o_x + (fdf->d_x - fdf->o_x) * ratio;
		Y = fdf->o_y + (fdf->d_y - fdf->o_y) * ratio;
		if (X >= 0 && X < SCREEN_X && Y >= 0 && Y < SCREEN_Y)
			pixel_put(fdf->pixel, X, Y, (b << 16) + (g << 8) + (r));
		i++;
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
