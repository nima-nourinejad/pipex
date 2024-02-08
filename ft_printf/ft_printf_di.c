/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:26:10 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 16:07:59 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_edge(int n)
{
	int	b;

	if (n == 0)
	{
		b = ft_putchar('0');
		if (b == -1)
			return (-1);
		return (1);
	}
	b = ft_putstr("-2147483648");
	if (b == -1)
		return (-1);
	return (11);
}

static int	ft_power10(int n)
{
	if (n == 0)
		return (1);
	return (10 * ft_power10(n - 1));
}

static int	ft_len(int n)
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

int	ft_printf_di(int n)
{
	int	len;
	int	k;
	int	i;

	if (n == 0 || n == -2147483648)
		return (ft_edge(n));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		return (ft_printf_di(-1 * n) + 1);
	}
	len = ft_len(n);
	i = len;
	k = ft_power10(len - 1);
	while (i)
	{
		if (ft_putchar((n / k) + '0') == -1)
			return (-1);
		n %= k;
		k /= 10;
		i--;
	}
	return (len);
}
