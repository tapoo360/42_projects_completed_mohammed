/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:25:09 by marvin            #+#    #+#             */
/*   Updated: 2026/11/01 15:25:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libput.h"

static void ft_putnbr_base_fd(unsigned long long int n, const char *base, int fd)
{
	if (n >= 16)
		ft_putnbr_base_fd(n / 16, base, fd);
	ft_putchar_fd(base[n % 16], fd);
}

static int  ft_numlen_hex(unsigned long long int n)
{
	int len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	_ft_putnbr_hex(unsigned long long int n, int *count, char format)
{
	if (format == 'x')
		ft_putnbr_base_fd(n, "0123456789abcdef", 1);
	else if (format == 'X')
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
	else
		return (-1); // Invalid format specifier

	if (n == 0)
		(*count)++;
	else
		*count += ft_numlen_hex(n);

	return (1);
}
