/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:42:06 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/15 06:47:18 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (!(ft_strlen(s) - start))
		return (NULL);
	substr = (char *) malloc((len) + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
