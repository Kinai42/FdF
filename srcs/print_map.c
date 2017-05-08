/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:58:01 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/05 19:20:20 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

	void	*ft_origin_map(int SCREEN_X, int SCREEN_Y, int m_x, int m_y)
{
	t_orign	map;

	map->
}



int		draw_line(int o_x, int o_y, int d_x, int d_y, char *pixel)
{
	t_drawline	*line;
	int			x;
	int			y;
	int			origin[2];
	int			dest[2];

	origin[0] = o_x;
	origin[1] = o_y;
	dest[0] = d_x;
	dest[1] = d_y;
	if (!(line = malloc(sizeof(t_drawline))))
		return (-1);
	line->i = 0;
	line->distance = sqrt(pow((dest[X] - origin[X]), 2) +
			pow((dest[Y] - origin[Y]), 2));
	while (line->i < line->distance)
	{
		line->ratio = (double)line->i / (double)line->distance;
		x = origin[X] + (dest[X] - origin[X]) * line->ratio;
		y = origin[Y] + (dest[Y] - origin[Y]) * line->ratio;
		pixel_put(pixel, x, y, (255 << 16) + (255 << 8) + (255));
		line->i++;
	}
	return (0);
}
