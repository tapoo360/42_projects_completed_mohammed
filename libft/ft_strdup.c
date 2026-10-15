/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:15:39 by marvin            #+#    #+#             */
/*   Updated: 2026/10/14 20:53:19 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	unsigned int	string_count;
	unsigned int	i;
	char			*dup;

	string_count = ft_strlen(s);
	if (!string_count)
	{
		return (NULL);
	}
	dup = (char *) malloc(string_count + 1);
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
