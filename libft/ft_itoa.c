/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:52:56 by nima              #+#    #+#             */
/*   Updated: 2023/11/08 14:55:40 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_edge_itoa(int n)
{
	char	*m;

	if (n == -2147483648)
	{
		m = ft_strdup("-2147483648");
	}
	else if (n == 2147483647)
	{
		m = ft_strdup("2147483647");
	}
	else
	{
		m = ft_strdup("0");
	}
	return (m);
}

static int	ft_power10(int n)
{
	if (n == 0)
		return (1);
	return (10 * ft_power10(n - 1));
}

static int	ft_len(int n)
{
	int	i;
	int	buffer;

	i = 1;
	if (n < 0)
		buffer = -1 * n;
	else
		buffer = n;
	while (buffer >= 10)
	{
		i++;
		buffer = buffer / 10;
	}
	return (i);
}

static char	*ft_fill(char *m, int n, int len, int s_len)
{
	int	i;

	i = 0;
	while (i < s_len)
	{
		if (n < 0)
		{
			m[i] = '-';
			n = -1 * n;
			i++;
		}
		m[i] = n / ft_power10 (len - 1) + 48;
		n = n % ft_power10(len - 1);
		len--;
		i++;
	}
	return (m);
}

char	*ft_itoa(int n)
{
	int		len;
	int		s_len;
	char	*m;

	if (n == -2147483648 || n == 2147483647 || n == 0)
		return (ft_edge_itoa(n));
	len = ft_len (n);
	if (n < 0)
		s_len = len + 1;
	else
		s_len = len;
	m = malloc((s_len + 1) * sizeof(char));
	if (m == 0)
		return (0);
	m [s_len] = '\0';
	m = ft_fill(m, n, len, s_len);
	return (m);
}
