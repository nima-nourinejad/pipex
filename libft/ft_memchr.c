/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:32:14 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 14:58:47 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int c1, size_t n)
{
	size_t			i;
	char			*s;
	unsigned char	c;

	s = (char *)p;
	c = (unsigned char) c1;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
