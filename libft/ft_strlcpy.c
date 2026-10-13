/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 20:17:32 by marvin            #+#    #+#             */
/*   Updated: 2026/10/13 20:17:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int ft_strlen(const char *str)
{
    unsigned int len = 0;
    while (str[len])
        len++;
    return (len);
}

unsigned int ft_strlcpy(char *dest, const char *src, unsigned int size)
{
    unsigned int i;

    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while (src[i] && i < size - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}
