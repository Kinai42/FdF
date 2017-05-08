/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:02:54 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/08 21:14:35 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>

int		act_windows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

void		start_fdf(t_fdf *fdf)
{
	int		win_x;
	int		win_y;

	win_x = 500;//Taille du fdf->tab * %
	win_y = 500;//Taille du fdf->tab * %
	if ((fdf->mlx = mlx_init()) && (fdf->win = mlx_new_window(fdf->mlx, win_x, win_y, "FDF")))
	{
		mlx_key_hook(fdf->win, act_windows, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		write(1, "error\n", 6);
}
