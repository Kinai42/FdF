/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:58:01 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/10 02:25:46 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

void	coord(t_fdf *fdf)
{
	int		i;

	i = 0;
	printf("entre dans coord OK\n");
	fdf->origin_x = (SCREEN_X / 2) - (fdf->width / 2);
	fdf->origin_y = (SCREEN_Y / 2) - (fdf->height / 2);
	while (i < fdf->width)
		fdf->x[i] = fdf->origin_x + (fdf->pas * i);
	i = 0;
	while (i < fdf->height)
		fdf->y[i] = fdf->origin_y + (fdf->pas * i);
}

int		print_map(t_fdf *fdf)
{
	int		h;
	int		w;

	h = -1;
	w = -1;
	printf("entree dans print_map\n");
	while (++h < fdf->height)
	{
		w = -1;
		while (++w < fdf->width - 1)
		{
			draw_line(fdf->x[w], fdf->y[h], fdf->x[w + 1], fdf->y[h], fdf);
			if (h < fdf->height - 1)
				draw_line(fdf->x[w], fdf->y[h], fdf->x[w], fdf->y[h + 1], fdf);
		}
	}
	printf("%d%d\n", fdf->height, fdf->width);
	return (0);
}

int		draw_line(int o_x, int o_y, int d_x, int d_y, t_fdf *fdf)
{
	int			i;
	int			distance;
	int			ratio;
	int			x;
	int			y;

	i = 0;
	printf("entree de draw_line\n");
	coord(fdf);
	distance = sqrt(pow((d_x - o_x), 2) +
			pow((d_y - o_y), 2));
	printf("%d\n", distance);
	while (i < distance)
	{
		printf("while de draw_line\n");
		ratio = (double)i / (double)distance;
		x = o_x + (d_x - o_x) * ratio;
		y = o_y + (d_y - o_y) * ratio;
		pixel_put(fdf->pixel, x, y, (fdf->colors[0] << 16) + (fdf->colors[1] << 8) + (fdf->colors[2]));
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
	printf("pixel_put OK\n");
}
