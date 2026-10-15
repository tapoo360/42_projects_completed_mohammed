/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:34:33 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/15 10:41:09 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_may_of(char const *s, char const *set)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (strchr(set, s[i]))
			count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_string;
	int		strlen;
	int		i;
	int		count;

	if (s1 == NULL)
		return (NULL);
	strlen = ft_strlen(s1);
	count = strlen - how_may_of(s1, set);
	trimed_string = (char *) malloc(count + 1);
	if (!trimed_string)
		return (NULL);
	i = -1;
	count = 0;
	while (s1[++i])
		if (!strchr(set, s1[i]))
			trimed_string[count++] = s1[i];
	trimed_string[count] = '\0';
	return (trimed_string);
}
