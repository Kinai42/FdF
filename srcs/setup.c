/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 21:45:07 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/19 07:08:37 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_fdf		*ft_init(char *av)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		return (0);
	fdf->width = 0;
	fdf->height = ft_height_map(av);
	fdf->zoom = 3;
	fdf->theme = 1;
	if (!(fdf->tab = (int **)malloc(sizeof(int *) * (fdf->height))))
		return (0);
	fdf->endian[0] = 32;
	fdf->endian[1] = 4 * SCREEN_X;
	fdf->endian[2] = 0;
	return (fdf);
}

int			*insert_tab(int alt, int *tab, int size)
{
	int		*new_tab;

	if (!(new_tab = malloc(sizeof(int) * (size + 1))))
		return (0);
	new_tab[size] = alt;
	while (size--)
		new_tab[size] = tab[size];
	return (new_tab);
}

int			ft_atoi_check(char *str)
{
	int		result;
	int		sign;

	result = 0;
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
			result = result * 10 + *str - '0';
		else
		{
			write(1, "invalid file\n", 13);
			exit(0);
		}
		str++;
	}
	return (result * sign);
}

int			newline(t_fdf *fdf, char *line, int y)
{
	char	**tab_char;
	int		alt_map;
	int		i;

	i = 0;
	if (!(tab_char = ft_strsplit(line, ' ')))
		return (0);
	fdf->width = ft_tablen(tab_char);
	while (tab_char[i])
	{
		alt_map = ft_atoi_check(tab_char[i]);
		fdf->tab[y] = insert_tab(alt_map, fdf->tab[y], i);
		free(tab_char[i++]);
	}
	free(tab_char);
	return (1);
}

t_fdf		*ft_setup(char *av)
{
	t_fdf	*fdf;
	int		fd;
	char	*line;
	int		y;

	y = 0;
	if ((fd = open(av, O_RDONLY)) == -1 || !(fdf = ft_init(av)))
	{
		write(1, "error", 5);
		return (0);
	}
	if (!(fdf->tab = (int **)malloc(sizeof(int *) * fdf->height)))
		return (0);
	while (get_next_line(fd, &line))
	{
		if (!newline(fdf, line, y))
		{
			write(1, "FdF: map invalid\n", 17);
			return (0);
		}
		y++;
		free(line);
	}
	coord(fdf);
	free(line);
	!fdf->width ? write(1, "FdF: map invalid\n", 17) : 0;
	return (fdf->width ? fdf : 0);
}
