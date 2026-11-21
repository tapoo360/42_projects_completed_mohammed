/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:40:46 by marvin            #+#    #+#             */
/*   Updated: 2026/11/21 10:40:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	fill(int fd, t_stash *s)
{
	ssize_t	n;

	if (!ft_reserve(s, BUFFER_SIZE))
		return (-1);
	n = read(fd, s->data + s->len, BUFFER_SIZE);
	if (n > 0)
		s->len += n;
	return (n);
}

static ssize_t	line_len(int fd, t_stash *s)
{
	size_t	off;
	ssize_t	n;

	off = 0;
	n = 1;
	while (1)
	{
		off = ft_find_nl(s->data, s->start + off, s->len) - s->start;
		if (s->start + off < s->len)
			return ((ssize_t)off + 1);
		if (n == 0)
			return ((ssize_t)off);
		n = fill(fd, s);
		if (n < 0)
			return (-1);
	}
}

char	*get_next_line(int fd)
{
	static t_stash	s[FD_MAX];
	char			*line;
	ssize_t			len;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	len = line_len(fd, &s[fd]);
	if (len <= 0)
		return (ft_free_stash(&s[fd]));
	line = malloc((size_t)len + 1);
	if (!line)
		return (ft_free_stash(&s[fd]));
	ft_copy(line, s[fd].data + s[fd].start, (size_t)len);
	line[len] = '\0';
	s[fd].start += (size_t)len;
	if (s[fd].start == s[fd].len)
		ft_free_stash(&s[fd]);
	return (line);
}
