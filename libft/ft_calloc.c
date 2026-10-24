/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:12:05 by marvin            #+#    #+#             */
/*   Updated: 2026/10/24 08:45:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmems, size_t size)
{
	void	*p;
	if (size == 0 || nmems == 0)
		return (malloc(0));
	if (nmems != 0 && size > SIZE_MAX / nmems)
    	return NULL;
	p  = malloc(nmems * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0 , nmems * size);
	return (p);
}
