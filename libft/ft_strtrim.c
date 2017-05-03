/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 22:39:08 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/15 06:28:40 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	blankcheck(const int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(const char *s)
{
	unsigned int	i;
	unsigned long	j;
	size_t			k;
	char			*s2;

	if (!s)
		return (NULL);
	i = 0;
	k = ft_strlen(s);
	while (blankcheck(s[k - 1]))
		k--;
	while (blankcheck(s[i]))
		i++;
	if (!s[i])
	{
		s2 = ft_strnew(0);
		return (s2);
	}
	j = k - i;
	s2 = ft_strsub(s, i, j);
	return (s2);
}
