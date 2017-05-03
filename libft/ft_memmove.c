/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 03:00:16 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/16 03:00:20 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	const char		*src2;

	i = 0;
	src2 = (const char *)src;
	if (dst > src)
		while (len--)
			((char *)dst)[len] = ((const char *)src)[len];
	else
		while (len--)
			((char *)dst)[i++] = *src2++;
	return (dst);
}
