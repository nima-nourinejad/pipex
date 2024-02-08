/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:18 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 15:01:40 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (dstsize != 0)
	{
		if (ft_strlen(src) < dstsize)
		{
			ft_memcpy(dst, src, ft_strlen(src));
			*(dst + ft_strlen(src)) = '\0';
		}
		else
		{
			ft_memcpy(dst, src, (dstsize - 1));
			*(dst + (dstsize - 1)) = '\0';
		}
	}
	return (ft_strlen(src));
}
