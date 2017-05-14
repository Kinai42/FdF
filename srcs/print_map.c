/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:58:01 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/14 08:32:11 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void	coord(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->origin_x = ((SCREEN_X / 2) - (fdf->width / 2)) + 255;
	fdf->origin_y = 20;
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
		fdf->o_x = fdf->origin_x - (20 * h);
		fdf->o_y = fdf->origin_y + (20 * h) ;
		while (w < fdf->width)
		{
			fdf->d_x = fdf->o_x + 20;
			fdf->d_y = fdf->o_y + 20 - (2 * (fdf->tab[h][w]));
			if (fdf->tab[h][w] == 0)
				draw_line(fdf, 255, 0, 255);
			fdf->o_x = fdf->d_x;
			fdf->o_y = fdf->d_y;
			w++;
		}
	}
	return (0);
}

int		prnt_line_y(f_fdf * fdf)
{

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
