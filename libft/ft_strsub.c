/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 03:06:05 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/16 03:06:07 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*fresh;

	if (!s)
		return (NULL);
	i = 0;
	if (!(fresh = malloc(sizeof(char) * len + 1)))
		return (NULL);
	fresh[len] = '\0';
	while (len--)
		fresh[i++] = s[start++];
	return (fresh);
}
