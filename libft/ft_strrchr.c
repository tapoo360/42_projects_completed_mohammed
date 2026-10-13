/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:23:27 by marvin            #+#    #+#             */
/*   Updated: 2026/10/13 21:23:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
    char	*last_occurrence;

    last_occurrence = NULL;
    while (*s)
    {
        if (*s == (char)c)
            last_occurrence = (char *)s;
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (last_occurrence);
}