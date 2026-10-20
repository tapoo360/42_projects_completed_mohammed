/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:39:41 by marvin            #+#    #+#             */
/*   Updated: 2026/10/16 16:39:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	digit_number(int n)
{
	unsigned int	count;

	if (n == 0)
	{
		return (1);
	}
	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	*create_signed_string(int value)
{
	char	*arr;
	int		digits;

	digits = digit_number(value);
	if (value < 0)
	{
		arr = (char *) malloc(digits + 2);
		arr[0] = '-';
		arr[digits + 1] = '\0';
		return (arr);
	}
	else if (value == 0)
	{
		arr = (char *)malloc(2);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	else
	{
		arr = (char *)malloc(digits + 1);
		arr[digits] = '\0';
		return (arr);
	}
}

static void	if_less_than_zero(char number[], int digits, size_t value)
{
	int	i;
	int	temp;

	i = digits;
	while (i > 0)
	{
		temp = value % 10;
		value /= 10;
		number[i] = temp + '0';
		i--;
	}
}

static void	if_greater_then_zero(char number[], int digits, size_t value)
{
	int	i;
	int	temp;

	i = digits - 1;
	while (i > -1)
	{
		temp = value % 10;
		value /= 10;
		number[i] = temp + '0';
		i--;
	}
}

char	*ft_itoa(int n)
{
	long int	temp;
	char		*ret;
	int			i;

	i = digit_number(n);
	ret = (char *)create_signed_string(n);
	if (n < 0)
	{
		temp = n * -1;
		if_less_than_zero(ret, i, temp);
		return (ret);
	}
	else if (n == 0)
	{
		return (ret);
	}
	else
	{
		temp = n;
		if_greater_then_zero(ret, i, temp);
		return (ret);
	}
}
