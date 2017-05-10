/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:42:09 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/10 02:43:58 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

# define SCREEN_X 1000
# define SCREEN_Y 1000
# define EXIT_SUCCES 0

# define RED	0xff0000
# define GREEN	0x00ff00
# define BLUE	0x0000ff

typedef struct		s_fdf
{
	int		*tab; //tableau d'altitude de la map
	int		*x; //tableau de coordonnees axe x
	int		*y; //tableau de coordonnees axe y

	int		width; //largeur de la map
	int		height; //hauteur de la map
	int		pas; //espace entre 2 points de la map en x et en y

	int		origin_x; // pixel de depart de l'impression de la map en x
	int		origin_y; // pixel de depart de l'impression de la map en x
	void	*mlx; 
	void	*win;
	char	*pixel;
	void	*image;

	int		colors[3];
	int		a;
	int		b;
	int		c;

}					t_fdf;

int		act_win(int keycode, void *param);
void	start_fdf(t_fdf *fdf);
t_fdf	*ft_setup(char *str);
t_fdf	*init(void);
int		newline(t_fdf *fdf, char *line);
int		ft_atoi_check(int *ptr, char *str);
int		*insert_tab(int nb, int *tab, int size);
void	coord(t_fdf *fdf);
int		print_map(t_fdf *fdf);
int		draw_line(int o_x, int o_y, int d_x, int d_y, t_fdf *fdf);
void	pixel_put(char *pixel, int x, int y, int color);
int		ft_height_map(int fd);

# endif
