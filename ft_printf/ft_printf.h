/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/13 13:30:00 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printf_s(char *s);
int		ft_printf_c(char c);
int		ft_printf_di(int n);
int		ft_printf_u(unsigned int n);
int		ft_printf_x(unsigned int x);
int		ft_printf_xx(unsigned int x);
int		ft_printf_p(unsigned long int p);
int		ft_strlen_int(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif // FT_PRINTF_H