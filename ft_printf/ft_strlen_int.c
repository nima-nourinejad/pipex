/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:49:58 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 14:53:51 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_int(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		if (*s == '\0')
			return (0);
		else
		{
			while (*s != '\0')
			{
				++s;
				++len;
			}
			return (len);
		}
	}
	else
		return (-1);
}
