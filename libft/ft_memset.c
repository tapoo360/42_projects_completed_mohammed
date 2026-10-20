/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:03:49 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/20 20:29:10 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*p;
	unsigned int	i;
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
