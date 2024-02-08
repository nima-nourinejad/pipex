/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:08:42 by nnourine          #+#    #+#             */
/*   Updated: 2023/12/04 15:56:52 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversions(va_list args, char f)
{
	if (f == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (f == 'c')
		return (ft_printf_c(va_arg(args, int)));
	else if (f == 'd' || f == 'i')
		return (ft_printf_di(va_arg(args, int)));
	else if (f == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (f == '%')
		return (ft_printf_c(f));
	else if (f == 'x')
		return (ft_printf_x(va_arg(args, unsigned int)));
	else if (f == 'X')
		return (ft_printf_xx(va_arg(args, unsigned int)));
	else if (f == 'p')
		return (ft_printf_p((unsigned long int)va_arg(args, void *)));
	return (-1);
}

static int	ft_printer(va_list args, const char *str, int len)
{
	int			b;

	while (*str)
	{
		if (*str == '%')
		{
			b = ft_conversions(args, *(str + 1));
			len = len + b - 2;
			str += 2;
		}
		else
			b = ft_putchar(*(str++));
		if (b == -1)
			return (-1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = ft_strlen_int(str);
	len = ft_printer(args, str, len);
	va_end(args);
	return (len);
}
