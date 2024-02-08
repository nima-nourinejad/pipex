/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:55:16 by nima              #+#    #+#             */
/*   Updated: 2023/11/07 18:11:31 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	l;
	size_t	i;

	if (s)
	{
		l = ft_strlen(s);
		i = 0;
		while (i < l)
		{
			f((unsigned int) i, &s[i]);
			i++;
		}
	}
}
