/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 01:30:26 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/12 04:03:26 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		start_fdf(t_fdf *fdf, char *av)
{

	SCREEN_X;//Taille du fdf->tab * %
	SCREEN_Y;//Taille du fdf->tab * %
	if ((fdf->mlx = mlx_init()) && (fdf->win = mlx_new_window(fdf->mlx, SCREEN_X, SCREEN_Y, av)))
	{
		//		print_map(fdf);
		fdf->image = mlx_new_image(fdf->mlx, SCREEN_X, SCREEN_Y);
		fdf->pixel = mlx_get_data_addr (fdf->image, &fdf->endian[0], &fdf->endian[1], &fdf->endian[2]);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
		//	mlx_key_hook(fdf->win, act_windows, fdf);
		fdf->o_x = 10;
		fdf->o_y = 1;
		fdf->d_x = 10;
		fdf->d_y = 10;
		fdf->endian[0] = 32;
		fdf->endian[1] = 4 * SCREEN_X;
		fdf->endian[2] = 0;
		draw_line(fdf, 255, 0, 0);
		mlx_string_put(fdf->mlx, fdf->win, 2, 2, 0x00FF0000, "MENU");
		mlx_string_put(fdf->mlx, fdf->win, 910, 970, 0x00FF0050, "DBAUDUIN");

		//	menu(fdf);
		mlx_loop(fdf->mlx);
		free (fdf);
	}
	else
		write(1, "error\n", 6);
}


/*void	menu(t_fdf *fdf)
{

	fdf->o_x = 10;
	fdf->o_y = 1;
	fdf->d_x = 10;
	fdf->d_y = 10;
	fdf->endian[0] = 32;
	fdf->endian[1] = 4 * SCREEN_X;
	fdf->endian[2] = 0;
	draw_line(fdf, 255, 255, 255);
	mlx_string_put(fdf->mlx, fdf->win, 2, 2, 0x00FF0000, "MENU");
	mlx_string_put(fdf->mlx, fdf->win, 910, 970, 0x00FF0050, "DBAUDUIN");

}*/
