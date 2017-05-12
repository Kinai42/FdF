/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:42:09 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/12 03:38:15 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"

# include <stdio.h>

# define SCREEN_X 1000
# define SCREEN_Y 1000

# define RED	0xff0000
# define GREEN	0x00ff00
# define BLUE	0x0000ff

typedef struct		s_fdf
{
	int		**tab; //tableau d'altitude de la map
	int		width; //largeur de la map
	int		height; //hauteur de la map



	int		o_x; //coordonnees axe x
	int		o_y; //coordonnees axe y
	int		d_x;
	int		d_y;
	
	int		origin_x; // pixel de depart de l'impression de la map en x
	int		origin_y; // pixel de depart de l'impression de la map en x



	void	*mlx; 
	void	*win;
	char	*pixel;
	void	*image;

	int		endian[3];

}					t_fdf;

//int		act_win(int keycode, void *param);
void	start_fdf(t_fdf *fdf, char *av);
t_fdf	*ft_setup(char *av);
t_fdf	*ft_init(char *av);
int		newline(t_fdf *fdf,char *line, int y);
int		ft_atoi_check(char *tab);
int		*insert_tab(int alt_map, int *tab, int size);



//void	coord(t_fdf *fdf);
int		print_map(t_fdf *fdf);
int		draw_line(t_fdf *fdf, int r, int g, int b);
void	pixel_put(char *pixel, int x, int y, int color);
int		ft_height_map(char *av);
void	menu(t_fdf *fdf);

# endif
