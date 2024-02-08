/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:56 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 14:57:09 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	if (len == 0 || dst == src)
		return (dst);
	if (dst > src && dst < (src + len))
	{
		i = (int)len - 1;
		d = (char *)dst;
		s = (char *)src;
		while (i >= 0)
		{
			*(d + i) = *(s + i);
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
