/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:05:36 by marvin            #+#    #+#             */
/*   Updated: 2026/10/13 22:05:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strnstr(const char *big, const char *little, unsigned int len)
{
    unsigned int    i;
    unsigned int    j;

    if (*little == '\0')
        return ((char *)big);
    i = 0;
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] && little[j] && (i + j) < len && big[i + j] == little[j])
            j++;
        if (little[j] == '\0')
            return ((char *)(big + i));
        i++;
    }
    return (NULL);
}