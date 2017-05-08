/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:55:59 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/08 21:33:34 by dbauduin         ###   ########.fr       */
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
	if (!(tab = ft_strsplit(line, ' ')) || ft_tablen(tab) == 0)
		return (0);
	fdf->width == 0 ? fdf->width = ft_tablen(tab) : 0;
	while (tab[i])
	{
		if (!ft_atoi_check(&alt, tab[i]) || !(fdf->tab = insert_tab(alt_tab, fdf->tab, fdf->size)))
			return (0);
		free(tab[i++]);
		fdf->size++;
	}
	free(tab);
	return (1);
}

t_fdf			*init(void)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (0);
	fdf->size = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->posx = 0;
	fdf->posy = 0;
	fdf->colors[0] = RED;
	fdf->colors[1] = GREEN;
	fdf->colors[2] = BLUE;
	return (fdf);
}

t_fdf			*ft_setup(char *str)
{
	t_fdf	*fdf;
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1 ||	!(fdf = init()))
	{
		write (1,"error", 5);	
		return (0);
	}
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
	!fdf->size ? write(1, "FdF: map invalid\n", 17) : 0;
	return (fdf->size ? fdf : 0);
}

