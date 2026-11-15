/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:57:46 by marvin            #+#    #+#             */
/*   Updated: 2026/11/15 16:56:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*free_gnl(t_gnl *line)
{
	if (line)
	{
		free(line->line);
		free(line);
	}
	return (NULL);
}

static t_gnl	*init_line(void)
{
	t_gnl	*line;

	line = malloc(sizeof(t_gnl));
	if (!line)
		return (NULL);
	line->line = malloc(BUFFER_SIZE + 1);
	if (!line->line)
	{
		free(line);
		return (NULL);
	}
	line->line_size = BUFFER_SIZE + 1;
	line->current_index = 0;
	line->completed_f = 0;
	return (line);
}

static t_gnl	*buffer_to_line(int fd, t_BUFFER *buffer)
{
	t_gnl	*line;
	int		read_status;

	line = init_line();
	if (!line)
		return (NULL);
	while (!line->completed_f)
	{
		if (buffer->consum_f || buffer->remains_num == 0)
		{
			read_status = fill_buffer(fd, buffer);
			if (read_status == -1)
				return (free_gnl(line));
			if (read_status == 0)
				break ;
		}
		if (!process_buffer_to_line(buffer, line))
			return (free_gnl(line));
	}
	if (line->current_index == 0)
		return (free_gnl(line));
	return (line);
}

char	*get_next_line(int fd)
{
	static t_BUFFER	buffer;
	t_gnl			*line;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = buffer_to_line(fd, &buffer);
	if (!line)
	{
		buffer.remains_num = 0;
		buffer.buf_index = 0;
		buffer.consum_f = 0;
		return (NULL);
	}
	result = line->line;
	free(line);
	return (result);
}