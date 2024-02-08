/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:20:02 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 16:33:55 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	ft_power16(int n)
{
	if (n == 0)
		return (1);
	return (16 * ft_power16(n - 1));
}

static	int	ft_len(unsigned long int p)
{
	int	len;

	if (p == 0)
		return (1);
	len = 0;
	while (p)
	{
		len++;
		p /= 16;
	}
	return (len);
}

static int	ft_printf_px(unsigned long int x)
{
	int					len;
	unsigned long int	k;

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

int	ft_printf_p(unsigned long int p)
{
	int	len;
	int	b;

	if (p == 0)
	{
		b = ft_putstr("0x0");
		if (b == -1)
			return (-1);
		return (3);
	}
	b = ft_putstr("0x");
	if (b == -1)
		return (-1);
	len = ft_printf_px(p);
	return (2 + len);
}
