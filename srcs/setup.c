/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:55:59 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/10 03:11:43 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int				*insert_tab(int nb, int *tab, int size)
{
	int		*new_tab;

	if (!(new_tab = malloc(sizeof(int) * (size + 1))))
		return (0);
	new_tab[size] = nb;
	while (size--)
		new_tab[size] = tab[size];
	tab ? free(tab) : 0;
	return (new_tab);
}

int				ft_atoi_check(int *ptr, char *str)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	if ((*str == '-' || *str == '+') && *(str + 1))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * 10 + *str - '0';
		else
			return (0);
		str++;
	}
	*ptr = nb * sign;
	return (1);
}

int				newline(t_fdf *fdf, char *line)
{
	char	**tab;
	int		alt_map;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		return (0);
	fdf->width = ft_tablen(tab);
	printf("%d\n", fdf->width);
	fdf->height++;
	if (!(fdf->tab = (int *)malloc(sizeof(int) * fdf->height)))
	return (0);
	printf("ok2\n");
	while (tab[i])
	{
		if (!ft_atoi_check(&alt_map, tab[i]) || !(fdf->tab = insert_tab(alt_map, fdf->tab, fdf->width)))
			return (0);
		free(tab[i++]);
	}
	free(tab);
	return (1);
}

t_fdf			*init(int fd)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (0);
	fdf->width = 0;
	fdf->height = ft_height_map(fd);
	fdf->x = 0;
	fdf->y = 0;
	fdf->pas = 10;
	fdf->origin_x = 0;
	fdf->origin_y = 0;
	fdf->colors[0] = RED;
	fdf->colors[1] = GREEN;
	fdf->colors[2] = BLUE;
	fdf->a = 32;
	fdf->b = 4 * SCREEN_X;
	fdf->c = 0;
	return (fdf);
}

t_fdf			*ft_setup(char *str)
{
	t_fdf	*fdf;
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1 ||	!(fdf = init(fd)))
	{
		write (1,"error", 5);	
		return (0);
	}
	printf("ok1\n");
	while (get_next_line(fd, &line))
	{
		if (!newline(fdf, line))
		{
			write(1, "FdF: map invalid\n", 17);
			return (0);
		}
		free(line);
	}
	free(line);
	!fdf->width ? write(1, "FdF: map invalid\n", 17) : 0;
	return (fdf->width ? fdf : 0);
}

