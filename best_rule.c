/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:54:02 by nnourine          #+#    #+#             */
/*   Updated: 2024/01/31 11:31:56 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_find_best(t_rule *r1, t_rule *r2, t_rule *r3, t_rule *r4)
{
	return (ft_find_max4(((*r1).f + (*r1).x + (*r1).staus)
			, ((*r2).f + (*r2).x + (*r2).staus)
			, ((*r3).f + (*r3).x + (*r3).staus)
			, ((*r4).f + (*r4).x + (*r4).staus)));
}

static void	ft_rule_remover3(t_rule *r1, t_rule *r2, t_rule *r3)
{
	ft_rule_remover(r1);
	ft_rule_remover(r2);
	ft_rule_remover(r3);
}

static t_rule	*ft_best_rule(t_rule *r0, t_rule *r1, t_rule *r2, t_rule *r3)
{
	int	best;

	best = ft_find_best(r0, r1, r2, r3);
	if (best == 0)
	{
		ft_rule_remover3(r1, r2, r3);
		return (r0);
	}
	if (best == 1)
	{
		ft_rule_remover3(r0, r2, r3);
		return (r1);
	}
	if (best == 2)
	{
		ft_rule_remover3(r0, r1, r3);
		return (r2);
	}
	else
	{
		ft_rule_remover3(r0, r1, r2);
		return (r3);
	}
}

t_rule	*ft_final_rule(char *str, char **envp)
{
	t_rule	*r0;
	t_rule	*r1;
	t_rule	*r2;
	t_rule	*r3;

	r0 = ft_rule0_maker(str, envp);
	r1 = ft_rule1_maker(str, envp);
	r2 = ft_rule2_maker(str, envp);
	r3 = ft_rule3_maker(str, envp);
	return (ft_best_rule(r0, r1, r2, r3));
}
