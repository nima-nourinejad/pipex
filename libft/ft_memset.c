/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:45 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 14:57:31 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t size)
{
	size_t			i;
	unsigned char	v;
	unsigned char	*p;

	i = 0;
	v = (unsigned char) val;
	p = (unsigned char *) ptr;
	while (i < size)
	{
		*(p + i) = v;
		i++;
	}
	return (ptr);
}
