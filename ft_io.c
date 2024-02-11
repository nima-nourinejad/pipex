/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:38:50 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/11 17:24:43 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check_read(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '\0')
		return (0);
	if (access(str, R_OK) == 0)
		return (1);
	return (0);
}

static char	*ft_i_maker(char *i)
{
	char	*i0;
	char	*i1;

	i0 = ft_pos0_maker(i);
	if (!i0)
		exit (-6);
	if (ft_check_read(i0))
		return (i0);
	i1 = ft_pos1_maker(i);
	if (!i1)
		exit (-6);
	if (ft_check_read(i1))
	{
		free(i0);
		return (i1);
	}
	free(i1);
	return (i0);
}

t_io	ft_io(char *i, char *o)
{
	t_io	r;

	r.fd_null = open("null", O_WRONLY | O_CREAT, 0600);
	if (r.fd_null == -1)
		exit (-5);
	i = ft_i_maker(i);
	r.i = open(i, O_RDONLY);
	if (r.i == -1)
	{
		dup2(2, 1);
		ft_printf("pipex: %s: %s\n", i, strerror(errno));
		r.i = r.fd_null;
	}
	r.o = open(o, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (r.o == -1)
	{
		dup2(2, 1);
		ft_printf("pipex: %s: %s\n", o, strerror(errno));
	}
	free(i);
	return (r);
}
