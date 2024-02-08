/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:39:15 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 15:09:23 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rm_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] < 9 || s[i] > 13) && s[i] != 32)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_check_overflow(char *s)
{
	long	digit;
	long	temp;
	long	i;
	long	n;

	i = 0;
	n = 0;
	if (s[i] < '0' && s[i] > '9')
		return (1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - 48;
		temp = (LONG_MAX - digit) / 10;
		if (temp < n)
			return (0);
		n = 10 * n + digit;
		i++;
	}
	return (1);
}

static int	ft_strnbr(char *s)
{
	int	digit;
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (s[i] < '0' && s[i] > '9')
		return (0);
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - 48;
		n = n * 10 + digit;
		++i;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		sign;

	s = (char *)str;
	s = s + ft_rm_space (s);
	if (*s == '\0')
		return (0);
	sign = 1;
	if (*s == '+' || *s == '-' )
	{
		if (*s == '+')
			s++;
		else if (*s == '-')
		{
			sign = -1;
			s++;
		}
	}
	if (ft_check_overflow(s) == 0)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (ft_strnbr(s) * sign);
}
