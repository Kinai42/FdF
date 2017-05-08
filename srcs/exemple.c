/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:14:40 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/05 19:20:00 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int	main()
{
	t_fdf	*fdf;

	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_X, SCREEN_Y, "title");
	mlx_string_put(fdf->mlx, fdf->win, 2, 2, 0x00FF0000, "FDF PROJECT");
	mlx_key_hook(fdf->win, close_win, fdf);
	mlx_loop(fdf->mlx);
	free (fdf);
	return (0);
}
