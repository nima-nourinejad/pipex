/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:25:07 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 17:06:43 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_fullclean(void (*del)(void *), void *b, t_list *f)
{
	del(b);
	ft_lstclear(&f, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*f_start;
	t_list	*f_new;
	void	*buffer;

	if (!lst || !f || !del)
		return (0);
	buffer = f(lst->content);
	f_start = ft_lstnew(buffer);
	if (!f_start)
	{
		del(buffer);
		return (0);
	}
	f_new = f_start;
	lst = lst->next;
	while (lst)
	{
		buffer = f(lst->content);
		f_new->next = ft_lstnew(buffer);
		if (!f_new->next)
			return (ft_fullclean(del, buffer, f_start));
		f_new = f_new->next;
		lst = lst->next;
	}
	return (f_start);
}
