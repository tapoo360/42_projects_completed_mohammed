/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:03:49 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/17 17:31:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
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
