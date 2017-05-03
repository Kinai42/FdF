/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 04:48:54 by dbauduin          #+#    #+#             */
/*   Updated: 2017/05/03 17:58:48 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_slot	*get_slot(t_slot *s, int fd)
{
	t_slot	*slot;

	slot = s;
	while (slot && slot->fd != fd)
		slot = slot->next;
	if (!slot)
	{
		if (!(slot = malloc(sizeof(t_slot))) ||
				!(slot->save = ft_strnew(0)))
			return (0);
		slot->fd = fd;
		slot->next = NULL;
		while (s && s->next)
			s = s->next;
		if (s)
			s->next = slot;
	}
	return (slot);
}

static int		save(t_slot *slot, char **tmp, char ***line)
{
	if (!(*tmp = ft_strdup(slot->save)))
		return (-1);
	if (**tmp == '\n')
	{
		free(slot->save);
		slot->save = ft_strdup(*tmp + 1);
		free(*tmp);
		**line = ft_strnew(0);
		return (1);
	}
	free(slot->save);
	slot->save = ft_strchr(*tmp, '\n') ?
		ft_strdup(ft_strchr(*tmp, '\n') + 1) : ft_strnew(0);
	if (ft_strchr(*tmp, '\n'))
		*ft_strchr(*tmp, '\n') = '\0';
	**line = *tmp;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_slot		*s;
	t_slot				*slot;
	char				buf[BUFF_SIZE + 1];
	int					st;
	char				*tmp;

	if (!line || !(slot = get_slot(s, fd)))
		return (-1);
	s = s ? s : slot;
	while ((st = read(fd, buf, BUFF_SIZE)))
	{
		if (st == -1)
			return (-1);
		buf[st] = '\0';
		tmp = ft_strjoin(slot->save, buf);
		free(slot->save);
		slot->save = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(slot->save, '\n'))
			break ;
	}
	if (save(slot, &tmp, &line))
		return (1);
	return (!!(*tmp));
}
