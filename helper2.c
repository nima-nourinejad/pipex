/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:13:46 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/13 19:40:37 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_doule_pointer(char **m)
{
	int	k;

	k = 0;
	while (m[k])
	{
		free(m[k]);
		k++;
	}
	free (m);
}

void	ft_free_doule_and_single_pointer(char **m, char *s1, char *s2)
{
	if (m)
		ft_free_doule_pointer(m);
	if (s1)
		free (s1);
	if (s2)
		free (s2);
}

void	ft_free_ior(t_ior ior)
{
	if ((ior.io).i != -1)
		close((ior.io).i);
	if ((ior.io).o != -1)
		close((ior.io).o);
	if (ior.r1)
		ft_rule_remover(ior.r1);
	if (ior.r2)
		ft_rule_remover(ior.r2);
}

void	ft_free_ior_unlink(t_ior ior)
{
	if ((ior.io).i != -1)
		close((ior.io).i);
	if ((ior.io).o != -1)
		close((ior.io).o);
	if (ior.r1)
		ft_rule_remover(ior.r1);
	if (ior.r2)
		ft_rule_remover(ior.r2);
}

void	ft_free_rule_fd(t_rule *r, int fd)
{
	if (r)
		ft_rule_remover (r);
	if (fd != -1)
		close (fd);
}
