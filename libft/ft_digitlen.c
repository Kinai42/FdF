/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:13:47 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/16 02:56:32 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digitlen(int *n)
{
	int				size;
	long long int	ncpy;

	size = 1;
	if (*n < 0)
	{
		size += 1;
		*n *= -1;
	}
	ncpy = *n;
	while (ncpy /= 10)
		size++;
	return (size);
}
