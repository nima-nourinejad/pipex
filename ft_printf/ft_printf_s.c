/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:35:22 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 14:57:18 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *s)
{
	int	b;

	if (!s)
	{
		b = ft_putstr("(null)");
		if (b < 0)
			return (-1);
		return (6);
	}
	b = ft_putstr(s);
	if (b < 0)
		return (-1);
	return (ft_strlen_int(s));
}
