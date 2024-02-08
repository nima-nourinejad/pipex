/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:01:09 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 16:25:20 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_power16(int n)
{
	if (n == 0)
		return (1);
	return (16 * ft_power16(n - 1));
}

static	int	ft_len(unsigned int x)
{
	int	len;

	if (x == 0)
		return (1);
	len = 0;
	while (x)
	{
		len++;
		x /= 16;
	}
	return (len);
}

int	ft_printf_x(unsigned int x)
{
	int				len;
	unsigned int	k;

	len = ft_len(x);
	k = ft_power16(len - 1);
	while (k >= 1)
	{
		if (x / k <= 9)
		{
			if (ft_putchar((x / k) + '0') == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(((x / k) - 10) + 'a') == -1)
				return (-1);
		}
		x %= k;
		k /= 16;
	}
	return (len);
}
