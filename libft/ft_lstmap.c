/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 21:03:30 by marvin            #+#    #+#             */
/*   Updated: 2026/10/18 21:03:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	tmp = lst;
	ret = NULL;
	ft_lstadd_front(&ret, ft_lstnew(f(tmp->content)));
	tmp = tmp->next;
	while (tmp)
	{
		ft_lstadd_back(&ret, ft_lstnew(f(tmp->content)));
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
	return (ret);
}
