/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:07:04 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 15:04:14 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			l_start;
	char			*d;

	if (s == 0)
		return (0);
	if (start >= ft_strlen (s))
		return (ft_strdup(""));
	l_start = ft_strlen (s + start);
	if (l_start > len)
	{
		d = malloc((len + 1) * sizeof (char));
		if (d == 0)
			return (0);
		ft_memcpy (d, s + start, len);
		d[len] = '\0';
		return (d);
	}
	else
		return (ft_strdup (s + start));
}
