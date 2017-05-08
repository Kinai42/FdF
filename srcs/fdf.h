/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:42:09 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/08 21:03:28 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define SCREEN_X 1000
# define SCREEN_Y 1000
# define EXIT_SUCCES 0

# define SIZE	0

# define RED	0xff0000
# define GREEN	0x00ff00
# define BLUE	0x0000ff

typedef struct		s_fdf
{
	int		*tab;
	int		*x;
	int		*y;

	int		width;
	int		size;
	int		factor;

	int		posx;
	int		posy;
	void	*mlx;
	void	*win;

	int		colors[3];

}					t_fdf;

int		act_win(int keycode, void *param);
void	start_fdf(t_fdf *fdf);
t_fdf	*ft_setup(char *str);
t_fdf	*init(void);
int		newline(t_fdf *fdf, char *line);
int		ft_atoi_check(int *ptr, char *str);
int		*insert_tab(int nb, int *tab, int size);

# endif
