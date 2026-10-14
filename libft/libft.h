/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-al- <mabd-al-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:11:16 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/14 19:38:04 by mabd-al-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(const char *s);

void	ft_bzero(void *s, int n);

void	*ft_calloc(int count, int size);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

int		ft_isalnum(int c);

int		ft_tolower(int c);

void	*ft_memset(void *b, int c, int len);

void	*ft_memcpy(void *dst, const void *src, int n);

void	*ft_memmove(void *dst, const void *src, int len);

void	*ft_memchr(const void *s, int c, int n);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strdup(const char *s1);

char	*ft_strnstr(const char *haystack, const char *needle, int len);

int		ft_strncmp(const char *s1, const char *s2, int n);

int		ft_strlen(const char *s);

int		ft_strlcpy(char *dst, const char *src, int dstsize);

int		ft_strlcat(char *dst, const char *src, int dstsize);

int		ft_toupper(int c);

int		ft_memcmp(const void *s1, const void *s2, int n);

#endif