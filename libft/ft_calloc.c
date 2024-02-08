/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:15:24 by nima              #+#    #+#             */
/*   Updated: 2023/11/08 15:37:17 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*m;
	size_t	t;

	t = nmemb * size;
	if (nmemb && size)
	{
		if (size != t / nmemb || t > 4294967295)
			return (0);
	}
	m = malloc(t * sizeof(char));
	if (m == 0)
		return (0);
	ft_bzero(m, t);
	return ((void *)m);
}
