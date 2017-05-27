/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:51:45 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/27 00:03:52 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <sys/stat.h>

int		main(int ac, char **av)
{
	t_fdf		*fdf;
	struct stat	st;

	stat(av[1], &st);
	if (ac != 2 || !S_ISREG(st.st_mode))
	{
		write(1, "FdF : need a valid file in parametre\n", 37);
		return (0);
	}
	if (!(fdf = ft_setup(av[1])))
	{
	//	write(1, "FDF : file read error\n", 21);
		return (0);
	}
	system("afplay ./srcs/son.mp3 & ");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_X, SCREEN_Y, av[1]);
	start_fdf(fdf, 0, 0, 0);
	return (0);
}
