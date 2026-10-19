/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 19:11:16 by mabd-al-          #+#    #+#             */
/*   Updated: 2026/10/18 21:16:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

int				ft_atoi(const char *s);

void			ft_bzero(void *s, int n);

void			*ft_calloc(int count, int size);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

int				ft_isalnum(int c);

int				ft_tolower(int c);

void			*ft_memset(void *b, int c, int len);

void			*ft_memcpy(void *dst, const void *src, int n);

void			*ft_memmove(void *dst, const void *src, int len);

void			*ft_memchr(const void *s, int c, int n);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

char			*ft_strdup(const char *s1);

char			*ft_strnstr(const char *haystack, const char *needle, int len);

int				ft_strncmp(const char *s1, const char *s2, int n);

int				ft_strlen(const char *s);

int				ft_strlcpy(char *dst, const char *src, int dstsize);

int				ft_strlcat(char *dst, const char *src, int dstsize);

int				ft_toupper(int c);

int				ft_memcmp(const void *s1, const void *s2, int n);

char			**ft_split(const char *s, char c);

char			*strtrim(const char *s, char *set);

char			*ft_strjoin(const char *s1, const char *s2);

char			*itoa(int n);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

char			*ft_itoa(int n);
typedef struct 		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			ft_lstadd_front(t_list **lst, t_list *new);

unsigned int	ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list			*ft_lstnew(void *content)

#endif