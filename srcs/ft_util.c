/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 02:38:52 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/11 22:49:13 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_height_map(char *av)
{
	char	c;
	int		fd;
	int		height;

	height = 0;
	if (!(fd = open(av, O_RDONLY)))
		return (0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			height++;
	}
	return (height);
}
