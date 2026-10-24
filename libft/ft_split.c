/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:03:13 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/24 20:03:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*free_split(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int	fill_word(char **split, char const *s, char c, size_t *j)
{
	size_t	start;
	size_t	len;

	while (s[*j] && s[*j] == c)
		(*j)++;
	start = *j;
	while (s[*j] && s[*j] != c)
		(*j)++;
	len = *j - start;
	*split = ft_substr(s, start, len);
	return (*split != NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		if (!fill_word(&split[i], s, c, &j))
			return (free_split(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}
