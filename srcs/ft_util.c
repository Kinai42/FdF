/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 02:38:52 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/10 02:44:59 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	ft_height_map(int fd)
{
	char	c;
	int		height;

	height = 1;
while (read(fd, &c, 1))
{
	if (c == '\n')
		height++;
}
	return (height);
}
