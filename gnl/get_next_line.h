/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:25:37 by marvin            #+#    #+#             */
/*   Updated: 2026/11/17 20:25:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stash
{
	char	*data;
	size_t	start;
	size_t	len;
	size_t	cap;
}	t_stash;

char	*get_next_line(int fd);
size_t	ft_find_nl(const char *d, size_t from, size_t to);
void	ft_copy(char *dst, const char *src, size_t n);
int		ft_reserve(t_stash *s, size_t extra);
char	*ft_free_stash(t_stash *s);

#endif
