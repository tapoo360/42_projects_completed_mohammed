/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:25:24 by marvin            #+#    #+#             */
/*   Updated: 2026/11/17 20:25:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_find_nl(const char *d, size_t from, size_t to)
{
	while (from < to && d[from] != '\n')
		from++;
	return (from);
}

void	ft_copy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_free_stash(t_stash *s)
{
	free(s->data);
	s->data = NULL;
	s->start = 0;
	s->len = 0;
	s->cap = 0;
	return (NULL);
}

int	ft_reserve(t_stash *s, size_t extra)
{
	char	*tmp;
	size_t	cap;

	if (s->start > 0)
	{
		ft_copy(s->data, s->data + s->start, s->len - s->start);
		s->len -= s->start;
		s->start = 0;
	}
	if (s->cap - s->len >= extra)
		return (1);
	cap = s->cap * 2 + extra;
	tmp = malloc(cap);
	if (!tmp)
		return (0);
	ft_copy(tmp, s->data, s->len);
	free(s->data);
	s->data = tmp;
	s->cap = cap;
	return (1);
}
