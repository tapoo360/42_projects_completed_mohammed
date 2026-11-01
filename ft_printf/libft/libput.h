/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libput.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:46:37 by marvin            #+#    #+#             */
/*   Updated: 2026/11/01 14:46:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUT_H
# define LIBPUT_H
# include "libft.h"

int    _ft_putchar(char c, int *count);

int    _ft_putstr(char *s, int *count);

int    _ft_putnbr(int n, int *count);

int    _ft_putnbr_unsigned(unsigned long long int n, int *count);

int    _ft_putnbr_hex(unsigned long long int n, int *count, char format);

#endif