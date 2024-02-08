/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:20:13 by nima              #+#    #+#             */
/*   Updated: 2023/11/07 18:10:26 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power10_fd(int n)
{
	if (n == 0)
		return (1);
	return (10 * ft_power10_fd(n - 1));
}

static int	ft_len_fd(int n)
{
	int	i;
	int	buffer;

	i = 1;
	buffer = n;
	while (buffer >= 10)
	{
		i++;
		buffer = buffer / 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		i;

	i = 0;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -1 * n;
		}
		len = ft_len_fd (n);
		while (len > 0)
		{
			ft_putchar_fd((n / ft_power10_fd (len - 1) + '0'), fd);
			n = n % ft_power10_fd(len - 1);
			len--;
		}
	}
}
