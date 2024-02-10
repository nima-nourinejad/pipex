/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:08:29 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 13:40:33 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_find_max4(int x1, int x2, int x3, int x4)
{
	int	max;

	max = x1;
	if (max < x2)
		max = x2;
	if (max < x3)
		max = x3;
	if (max < x4)
		max = x4;
	if (max == x1)
		return (0);
	if (max == x2)
		return (1);
	if (max == x3)
		return (2);
	else
		return (3);
}

char	**ft_free_split(char ***m, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		free((*m)[k]);
		k++;
	}
	free (*m);
	return (0);
}

int	ft_triger_maker_sp(int triger, char c, char before_c, char divider)
{
	if (c == divider && before_c != '\\')
	{
		if (triger == 0)
			triger = 1;
		else
			triger = 0;
	}
	return (triger);
}

t_ior	*ft_free_exit_ior(t_ior ior, int ex)
{
	if ((ior.io).i != (ior.io).fd_null)
	{
		if ((ior.io).i != -1)
			close((ior.io).i);
		if ((ior.io).fd_null != -1)
			close((ior.io).fd_null);
	}
	else
	{
		if ((ior.io).fd_null != -1)
			close((ior.io).fd_null);
	}
	if ((ior.io).o != -1)
		close((ior.io).o);
	if (ior.r1)
		ft_rule_remover(ior.r1);
	if (ior.r2)
		ft_rule_remover(ior.r2);
	exit (ex);
}

void	ft_close_fd(int in, int out, int fd_null)
{
	if (in != fd_null)
	{
		if (in != -1)
			close(in);
		if (fd_null != -1)
			close(out);
	}
	else
	{
		if (fd_null != -1)
			close(out);
	}
	if (out != -1)
		close(out);
}
