/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 03:04:48 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/16 03:04:50 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*fresh;

	if (!s || !(f))
		return (NULL);
	len = ft_strlen(s);
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	fresh[len] = '\0';
	len = 0;
	while (s[len])
	{
		fresh[len] = f(len, s[len]);
		len++;
	}
	return (fresh);
}
