/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:55:20 by nnourine          #+#    #+#             */
/*   Updated: 2023/10/31 11:06:35 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	l1;
	size_t	l2;

	if (s1 == 0 && s2 == 0)
		return (ft_strdup(""));
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	l1 = ft_strlen (s1);
	l2 = ft_strlen (s2);
	d = malloc((l1 + l2 + 1) * sizeof (char));
	if (d == 0)
		return (0);
	ft_memcpy(d, s1, l1);
	ft_memcpy(d + l1, s2, l2);
	d[l1 + l2] = '\0';
	return (d);
}
