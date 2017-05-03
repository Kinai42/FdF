/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:19:37 by dbauduin          #+#    #+#             */
/*   Updated: 2017/04/15 10:04:35 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	fresh = NULL;
	if (lst && f)
	{
		fresh = (*f)(lst);
		fresh->next = ft_lstmap(lst->next, (*f));
		return (fresh);
	}
	return (NULL);
}
