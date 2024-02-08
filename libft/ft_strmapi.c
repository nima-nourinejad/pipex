/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:21:36 by nima              #+#    #+#             */
/*   Updated: 2023/11/08 15:02:33 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*m;
	size_t	l;
	size_t	i;

	if (s == 0)
		return (0);
	l = ft_strlen(s);
	m = malloc((l + 1) * sizeof(char));
	if (m == 0)
		return (0);
	m[l] = '\0';
	i = 0;
	while (i < l)
	{
		m[i] = f((unsigned int) i, s[i]);
		i++;
	}
	return (m);
}
