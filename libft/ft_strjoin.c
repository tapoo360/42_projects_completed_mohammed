/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 06:49:26 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/15 09:26:10 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*joint;
	unsigned int	count;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	joint = (char *)malloc(count + 1);
	if (!joint)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		joint[i] = s1[i];
		j++;
		i++;
	}
	i = -1;
	while (s2[++i])
		joint[i + j] = s2[i];
	joint[count] = '\0';
	return (joint);
}
