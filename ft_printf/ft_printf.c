/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:33:49 by marvin            #+#    #+#             */
/*   Updated: 2026/11/01 12:33:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	print_pointer(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		(*count) += 5;
		return (1);
	}
	ft_putstr_fd("0x", 1);
	(*count) += 2;
	_ft_putnbr_hex((unsigned long long int)ptr, count, 'x');
	return (1);
}

static int	handle_format(const char *format, va_list args, int *count)
{
	if (*format == 'c')
		return (_ft_putchar(va_arg(args, int), count));
	else if (*format == 's')
		return (_ft_putstr(va_arg(args, char *), count));
	else if (*format == 'd' || *format == 'i')
		return (_ft_putnbr(va_arg(args, int), count));
	else if (*format == 'u')
		return (_ft_putnbr_unsigned(va_arg(args, unsigned int), count));
	else if (*format == 'p')
	{	
		return (print_pointer(va_arg(args, void *), count));
	}
	else if (*format == 'x' || *format == 'X')
		return (_ft_putnbr_hex(va_arg(args, unsigned int), count, *format));
	else if (*format == '%')
		return (_ft_putchar('%', count));
	else
		return (-1); // Invalid format specifier
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_format(format, args, &count);
		}
		else
			_ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
