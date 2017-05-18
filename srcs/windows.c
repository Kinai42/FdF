/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 01:30:26 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/18 09:58:55 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		start_fdf(t_fdf *fdf, char *av)
{
	if ((fdf->mlx = mlx_init()) && (fdf->win = mlx_new_window(fdf->mlx, SCREEN_X, SCREEN_Y, av)))
	{
		fdf->image = mlx_new_image(fdf->mlx, SCREEN_X, SCREEN_Y);
		fdf->pixel = mlx_get_data_addr(fdf->image, &fdf->endian[0], &fdf->endian[1], &fdf->endian[2]);
		ft_menu(fdf);
		coord(fdf);
		print_line_x(fdf);
		print_line_y(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
		mlx_string_put(fdf->mlx, fdf->win, 2, 2, 0x00FFFFFF, "MENU");
		mlx_string_put(fdf->mlx, fdf->win, 2, 40, 0x00FFFFFF, "ZOOM");
		mlx_string_put(fdf->mlx, fdf->win, SCREEN_X - 100, SCREEN_Y - 30, 0x00FFFFFF, "DBAUDUIN");
		mlx_key_hook(fdf->win, act_windows, fdf);
	//	system("aplay ./scrs/son.mp3 & ");
		mlx_loop(fdf->mlx);
		free (fdf);
	}
	else
		write(1, "error\n", 6);
}

void	ft_menu(t_fdf *fdf)
{
	int i;

	i = -1;
	while (++i < 255 * 1.5)
	{
		fdf->o_x = i;
		fdf->o_y = 0;
		fdf->d_x = i;
		fdf->d_y = SCREEN_Y;
		draw_line(fdf, 255 - i / 1.5, 0, 0);
	}
	fdf->o_x = 0;
	fdf->o_y = 25;
	fdf->d_x = SCREEN_X;
	fdf->d_y = 25;
	draw_line(fdf, 255, 255, 255);
}

int			act_windows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
	//	system("killall afplay");
		exit(0);
	}
/*	if (keycode == 69 || keycode == 24)
		make_window(fdf, fdf->height + 0.25, fdf->xpos, fdf->ypos);
	if (keycode == 78 || keycode == 27)
		make_window(fdf, fdf->height - 0.25, fdf->xpos, fdf->ypos);
	if (keycode == 124)
		make_window(fdf, fdf->height, fdf->xpos + 10, fdf->ypos);
	if (keycode == 123)
		make_window(fdf, fdf->height, fdf->xpos - 10, fdf->ypos);
	if (keycode == 125)
		make_window(fdf, fdf->height, fdf->xpos, fdf->ypos + 10);
	if (keycode == 126)
		make_window(fdf, fdf->height, fdf->xpos, fdf->ypos - 10);
*/	return (0);
}
