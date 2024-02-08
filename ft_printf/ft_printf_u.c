/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:36:05 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 15:08:20 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_power10(unsigned int n)
{
	if (n == 0)
		return (1);
	return (10 * ft_power10(n - 1));
}

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_printf_u(unsigned int n)
{
	int	len;
	int	k;
	int	i;
	int	b;

	if (n == 0)
	{
		b = ft_putchar('0');
		if (b == -1)
			return (-1);
		return (1);
	}
	len = ft_len(n);
	i = len;
	k = ft_power10(len - 1);
	while (i)
	{
		b = ft_putchar((n / k) + '0');
		if (b == -1)
			return (-1);
		n %= k;
		k /= 10;
		i--;
	}
	return (len);
}
