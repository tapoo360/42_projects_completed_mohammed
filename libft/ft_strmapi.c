/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:24:19 by marvin            #+#    #+#             */
/*   Updated: 2026/10/17 11:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int		i;
	int		strlen;
	char	*ret;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	ret = malloc((strlen * sizeof(char)) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < strlen)
	{
		ret[i] = f((unsigned int) i, s[i]);
	}
	ret[i] = '\0';
	return (ret);
}
