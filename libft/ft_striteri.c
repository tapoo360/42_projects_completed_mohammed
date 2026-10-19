/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:53:10 by marvin            #+#    #+#             */
/*   Updated: 2026/10/17 11:53:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    count;
    unsigned int	i;

	if (!s)
		return;
	count = ft_strlen(s);
	i = -1;
	while (++i < count)
		f(i, &s[i]);
}
