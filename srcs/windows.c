/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 01:30:26 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/19 06:35:05 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		start_fdf(t_fdf *fdf, double zoom, int x, int y)
{
	fdf->image = mlx_new_image(fdf->mlx, SCREEN_X, SCREEN_Y);
	fdf->pixel = mlx_get_data_addr(fdf->image, &fdf->endian[0], &fdf->endian[1], &fdf->endian[2]);
	ft_menu(fdf);
	fdf->zoom += zoom;
	fdf->origin_x += x;
	fdf->origin_y += y;
	print_line_x(fdf);
	print_line_y(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	ft_header(fdf);
	mlx_key_hook(fdf->win, act_windows, fdf);
	mlx_hook(fdf->win, 17, 17, leave_window, fdf);
	mlx_loop(fdf->mlx);
	free (fdf);
}

void	draw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_menu(fdf);
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 0xffffff0, "ZOOM");
	mlx_string_put(fdf->mlx, fdf->win, 0, 20, 0xffffff0, "DEPTH");
	print_line_x(fdf);
	print_line_y(fdf);
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
		draw_line_menu(fdf, 255 - i / 1.5, 0, 0);
	}
	fdf->o_x = 0;
	fdf->o_y = 25;
	fdf->d_x = 400;
	fdf->d_y = 25;
	draw_line_menu(fdf, 255, 255, 255);
}

int			act_windows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	if (keycode == 69 || keycode == 78)
		keycode == 69 ? start_fdf(fdf, 1, 0, 0) : start_fdf(fdf, -1, 0, 0);
	if (keycode == 124 || keycode == 123)
		keycode == 124 ? start_fdf(fdf, 0, 10, 0) : start_fdf(fdf, 0, -10, 0);
	if (keycode == 125 || keycode == 126)
		keycode == 125 ? start_fdf(fdf, 0, 0, 10) : start_fdf(fdf, 0, 0, -10);
	ft_header(param);
	return (1);
}

void		ft_header(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 2, 2, 0x00FFFFFF, "MENU");
	mlx_string_put(fdf->mlx, fdf->win, 2, 40, 0x00FFFFFF, "HEIGHT :");
	mlx_string_put(fdf->mlx, fdf->win, 90, 41, 0x00FFFFFF, ft_itoa(fdf->zoom));
	mlx_string_put(fdf->mlx, fdf->win, 2, 78, 0x00FFFFFF, "ORIGIN X :");
	mlx_string_put(fdf->mlx, fdf->win, 110, 77, 0x00FFFFFF, ft_itoa(fdf->origin_x));
	mlx_string_put(fdf->mlx, fdf->win, 2, 96, 0x00FFFFFF, "ORIGIN Y :");
	mlx_string_put(fdf->mlx, fdf->win, 110, 97, 0x00FFFFFF, ft_itoa(fdf->origin_y));
	mlx_string_put(fdf->mlx, fdf->win, 2, 130, 0x00FFFFFF, "MOVE MAP : UP    OR    DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 2, 150, 0x00FFFFFF, "           LEFT  OR    RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 2, 180, 0x00FFFFFF, "HEIGHT   :  +    OR      -");
	mlx_string_put(fdf->mlx, fdf->win, 2, 96, 0x00FFFFFF, "");
	mlx_string_put(fdf->mlx, fdf->win, SCREEN_X - 100, SCREEN_Y - 30, 0x00FFFFFF, "DBAUDUIN");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 210, 0x00FFFFFF, "           :::      ::::::::");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 180, 0x00FFFFFF, "         :+:      :+:    :+:");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 150, 0x00FFFFFF, "       +:+ +:+         +:+");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 120, 0x00FFFFFF, "     +#+  +:+       +#+");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 90, 0x00FFFFFF, "    +#+#+#+#+#+   +#+");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 60, 0x00FFFFFF, "         #+#    #+#");
	mlx_string_put(fdf->mlx, fdf->win, 10, SCREEN_Y - 30, 0x00FFFFFF, "        ###   ########");
}
