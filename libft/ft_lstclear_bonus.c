/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:22:32 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/07 15:35:19 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer;

	if (lst && del)
	{
		while (*lst)
		{
			buffer = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = buffer;
		}
		lst = 0;
	}
}
