/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:51:45 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/12 02:06:55 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <unistd.h>

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
	{
		write(1, "FdF need a file in parametre\n", 29);
		return (0);
	}
	if (!(fdf = ft_setup(av[1])))
	{
		write(1, "FDF : read file error\n",21);
		return (0);
	}
	start_fdf(fdf, av[1]);
	return (0);
}
