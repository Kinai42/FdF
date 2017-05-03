/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 00:54:18 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/16 07:17:43 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		if (*s == c && *s + 1 != c)
			i++;
	if (s[0] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * count_words(s, c) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!(tab[i] = ft_strsub((char *)s, 0, (ft_strrlen(s, c)))))
				return (ft_cleaner(tab, i));
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
