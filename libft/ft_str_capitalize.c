/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_capitalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:51:36 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/13 22:56:44 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_capitalize(char *s)
{
	int first;

	first = 1;
	while (*s)
	{
		if (ft_isalnum(*s))
		{
			if (first && ft_islower(*s))
				*s += 32;
			if (!first && ft_isupper(*s))
				*s -= 32;
			first = 0;
		}
		else
			first = 1;
		s++;
	}
	return (s);
}
