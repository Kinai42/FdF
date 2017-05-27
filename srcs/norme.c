/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 22:58:33 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/27 02:18:23 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_header2(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 2, 130, C,
	"MOVE MAP : UP    OR    DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 2, 150, C,
	"           LEFT  OR    RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 2, 180, C,
	"HEIGHT   :  +    OR      -");
	mlx_string_put(fdf->mlx, fdf->win, SCREEN_X - 100, SCREEN_Y - 30, C,
	"DBAUDUIN");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 210, C,
	"       :::      ::::::::");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 180, C,
	"     :+:      :+:    :+:");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 150, C,
	"   +:+ +:+         +:+");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 120, C,
	" +#+  +:+       +#+");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 90, C,
	"+#+#+#+#+#+   +#+");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 60, C,
	"     #+#    #+#");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 30, C,
	"    ###   ########");
}

int			ft_setup2(const int fd, char **line, t_fdf *fdf)
{
	int		y;

	y = 0;
	while (get_next_line(fd, line))
	{
		if (!newline(fdf, *line, y))
		{
			write(1, "FdF: map invalid\n", 17);
			exit(0);
		}
		y++;
	}
	return (1);
}
