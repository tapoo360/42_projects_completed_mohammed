/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:03:13 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/16 14:38:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*tokenizer(char *s, char c, char **p)
{
	int		i;
	int		j;
	char	*token;

	i = 0;
	j = 0;
	while (s[j] != c)
		j++;
	token = (char *)malloc((j - i) + 1);
	while (i < j)
	{
		token[i] = s[i];
		i++;
	}
	token[i] = '\0';
	*p = token;
	while (s[i] == c)
		i++;
	return (s + i);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !i)
		{
			count++;
			i = 1;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		count;
	char	*token;
	char	**arr_str;
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)s;
	count = count_words(temp, c);
	arr_str = (char **) malloc((sizeof(char *) * count) + 1);
	if (!arr_str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		temp = tokenizer(temp, c, &token);
		arr_str[i] = token;
		i++;
	}
	arr_str[i] = NULL;
	return (arr_str);
}
