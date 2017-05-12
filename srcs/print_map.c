/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:58:01 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/12 03:55:40 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <math.h>

/*void	coord(t_fdf *fdf)
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
  printf("print_map %d,%d\n", h, fdf->height);
  while (++w < fdf->width)
  {
  printf("print_map %d,%d\n", w, fdf->width);
  draw_line(fdf->x[w], fdf->y[h], fdf->x[w + 1], fdf->y[h], fdf);
  if (h < fdf->height - 1)
  draw_line(fdf->x[w], fdf->y[h], fdf->x[w], fdf->y[h + 1], fdf);
  }
  }
  printf("%d%d\n", fdf->height, fdf->width);
  return (0);
  }
  */
int		draw_line(t_fdf *fdf, int r, int g, int b)
{
	int			i;
	int			distance;
	double		ratio;
	int			X;
	int			Y;

	i = 0;
	printf("%d..%d..%d..%d\n",fdf->o_x, fdf->o_y, fdf->d_x, fdf->d_y);
	distance = sqrt(pow((fdf->d_x - fdf->o_x), 2) + pow((fdf->d_y - fdf->o_y), 2));
	printf("%d\n", distance);
	while (i < distance)
	{
	//	printf("%d\n", i);
		ratio = (double)i / (double)distance;
		X = fdf->o_x + (fdf->d_x - fdf->o_x) * ratio;
		printf("%d\n", X);
		Y = fdf->o_y + (fdf->d_y - fdf->o_y) * ratio;
		printf("%d\n", Y);
		if (X >= 0 && X < SCREEN_X && Y >= 0 && Y < SCREEN_Y)
		{
	//		printf("a");
			pixel_put(fdf->pixel, X, Y, (r << 16) + (g << 8) + (b));
		}
		i++;
	}
	return (0);
}

void	pixel_put(char *pixel, int x, int y, int color)
{
	pixel += x * 4 + y * (4 * 1000);
	pixel[0] = color >> 16 & 0xff;
	pixel[1] = color >> 8 & 0xff;
	pixel[2] = color & 0xff;
}
