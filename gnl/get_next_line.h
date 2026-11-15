/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:58:39 by marvin            #+#    #+#             */
/*   Updated: 2026/11/15 16:56:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_get_next_line
{
	char	*line;
	size_t	current_index;
	size_t	line_size;
	char	completed_f;
}	t_gnl;

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	remains_num;
	size_t	buf_index;
	char	consum_f;
}	t_BUFFER;

char	*get_next_line(int fd);
char	*ft_realloc(void *ptr, size_t new_size, size_t old_size);
int		fill_buffer(int fd, t_BUFFER *buffer);
int		grow_line(t_gnl *line);
int		copy_until_nl(t_BUFFER *buf, t_gnl *line);
int		process_buffer_to_line(t_BUFFER *buf, t_gnl *line);

#endif