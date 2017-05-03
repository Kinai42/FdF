/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:14:40 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/03 20:02:50 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	y = 250;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "title");
	while (y < 700)
	{
		x = 299;
		while (++x < 700)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00DF1F1F);
			if (x % 50 == 0)
			{
				while (y < 700)
					mlx_pixel_put(mlx, win, x, y, 0x00DF1F1F);
			}	
			y = y + 50;
		}
	}
	mlx_loop(mlx);
}
