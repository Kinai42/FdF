/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 03:05:30 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/16 03:05:32 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	size_t			l;

	i = 0;
	l = ft_strlen(s2);
	if (l == 0)
		return ((char *)s1);
	while (s1[i] && size >= l)
	{
		j = 0;
		k = i;
		while (s1[k] == s2[j])
		{
			j++;
			k++;
			if (!s2[j])
				return (&((char *)s1)[i]);
		}
		i++;
		size--;
	}
	return (NULL);
}
