/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:01:46 by marvin            #+#    #+#             */
/*   Updated: 2026/11/01 15:01:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libput.h"

static int  ft_numlen(int n)
{
    int len = 0;
    if (n <= 0)
        len++;
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

int _ft_putnbr(int n, int *count)
{
    ft_putnbr_fd(n, 1);
    if (n == 0)
        (*count)++;
    else
        *count += ft_numlen(n);
    return (1);
}
