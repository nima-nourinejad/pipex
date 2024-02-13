/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:44:57 by nima              #+#    #+#             */
/*   Updated: 2024/02/13 13:09:23 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_all_delimiter(char const *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

char	**ft_split_all_delimiter(char const *s)
{
	char	**m;

	m = malloc(2 * sizeof (char *));
	if (m == 0)
		return (0);
	m[1] = 0;
	m[0] = ft_strdup(s);
	if (!m[0])
	{
		free(m);
		return (0);
	}
	return (m);
}

void	ft_free_ior1(t_ior ior)
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
	if (ior.r1)
		ft_rule_remover(ior.r1);
	unlink("null");
}

void	ft_free_ior2(t_ior ior)
{
	if ((ior.io).o != -1)
		close((ior.io).o);
	if (ior.r2)
		ft_rule_remover(ior.r2);
}
