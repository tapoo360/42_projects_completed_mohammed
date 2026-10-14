/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:08:50 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/12 17:09:42 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset(void *s, int c, unsigned int n)
{
	char			*p;
	int				i;
	unsigned char	sec_c;

	p = s;
	i = 0;
	sec_c = (unsigned char)c;
	while (i < n)
	{
		p[i] = sec_c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, int n)
{
	ft_memset(s, 0, n);
}
