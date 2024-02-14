/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:44:57 by nima              #+#    #+#             */
/*   Updated: 2024/02/14 15:07:38 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if ((ior.io).i != -1)
		close((ior.io).i);
	if (ior.r1)
		ft_rule_remover(ior.r1);
}

void	ft_free_ior2(t_ior ior)
{
	if ((ior.io).o != -1)
		close((ior.io).o);
	if (ior.r2)
		ft_rule_remover(ior.r2);
}
