/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:05:05 by marvin            #+#    #+#             */
/*   Updated: 2026/11/15 16:56:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	char	*new_buffer;
	char	*old_buffer;
	size_t	copy_size;
	size_t	index;

	if (new_size == 0)
		return (free(ptr), NULL);
	new_buffer = malloc(new_size);
	if (!new_buffer)
		return (NULL);
	old_buffer = (char *)ptr;
	copy_size = old_size;
	if (copy_size > new_size)
		copy_size = new_size;
	index = 0;
	while (old_buffer && index < copy_size)
	{
		new_buffer[index] = old_buffer[index];
		index++;
	}
	free(ptr);
	return (new_buffer);
}

int	fill_buffer(int fd, t_BUFFER *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer->buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0)
		return (0);
	buffer->buffer[bytes_read] = '\0';
	buffer->remains_num = bytes_read;
	buffer->buf_index = 0;
	buffer->consum_f = 0;
	return (1);
}

int	grow_line(t_gnl *line)
{
	char	*new_line;

	new_line = ft_realloc(
			line->line,
			line->line_size + BUFFER_SIZE + 1,
			line->line_size);
	if (!new_line)
		return (0);
	line->line = new_line;
	line->line_size += BUFFER_SIZE + 1;
	return (1);
}

int	copy_until_nl(t_BUFFER *buf, t_gnl *line)
{
	while (buf->buf_index < buf->remains_num)
	{
		if (line->current_index + 2 >= line->line_size)
			if (!grow_line(line))
				return (0);
		if (buf->buffer[buf->buf_index] == '\n')
			return (1);
		line->line[line->current_index++] = buf->buffer[buf->buf_index++];
	}
	return (2);
}

int	process_buffer_to_line(t_BUFFER *buf, t_gnl *line)
{
	int	status;

	status = copy_until_nl(buf, line);
	if (status == 0)
		return (0);
	if (status == 2)
	{
		buf->consum_f = 1;
		line->line[line->current_index] = '\0';
		return (1);
	}
	line->line[line->current_index++] = '\n';
	buf->buf_index++;
	line->completed_f = 1;
	line->line[line->current_index] = '\0';
	return (1);
}