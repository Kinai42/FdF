/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:42:09 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/19 06:34:47 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"

# include <stdio.h>

# define SCREEN_X 1250
# define SCREEN_Y 1000

# define RED	0xff0000
# define GREEN	0x00ff00
# define BLUE	0x0000ff

typedef struct		s_fdf
{
	int			**tab;
	int			width; //largeur d
	int			height;



	double		o_x;
	double		o_y;
	double		d_x;
	double		d_y;
	double		zoom;
	int			theme;

	int			origin_x;
	int			origin_y;

	void		*mlx; 
	void		*win;
	char		*pixel;
	void		*image;

	int		endian[3];

}					t_fdf;

int		act_windows(int keycode, void *param);
void	start_fdf(t_fdf *fdf, double zoom, int x, int y);
t_fdf	*ft_setup(char *av);
t_fdf	*ft_init(char *av);
int		newline(t_fdf *fdf,char *line, int y);
int		ft_atoi_check(char *tab);
int		*insert_tab(int alt_map, int *tab, int size);
void	get_colors_x(t_fdf *fdf, int h, int w);
void	get_colors_y(t_fdf *fdf, int h, int w);
void	ft_header(t_fdf *fdf);
int		leave_window(void);
void	coord(t_fdf *fdf);
int		print_line_x(t_fdf *fdf);
int		print_line_y(t_fdf*fdf);
int		draw_line(t_fdf *fdf, int r, int g, int b);
int		draw_line_menu(t_fdf *fdf, int r, int g, int b);
void	pixel_put(char *pixel, int x, int y, int color);
int		ft_height_map(char *av);
void	ft_menu(t_fdf *fdf);

# endif
