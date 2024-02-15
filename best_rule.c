/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:54:02 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/15 11:53:32 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_find_best(t_rule *r1, t_rule *r2, t_rule *r3, t_rule *r4)
{
	return (ft_find_max4(((*r1).f + (*r1).x)
			, ((*r2).f + (*r2).x)
			, ((*r3).f + (*r3).x)
			, ((*r4).f + (*r4).x)));
}

static t_rule	*ft_rule_remover3(t_rule *r1, t_rule *r2, t_rule *r3)
{
	if (r1)
		ft_rule_remover(r1);
	if (r2)
		ft_rule_remover(r2);
	if (r3)
		ft_rule_remover(r3);
	return (0);
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
	if (!r0)
		return (ft_rule_remover3(0, 0, 0));
	r1 = ft_rule1_maker(str, envp);
	if (!r1)
		return (ft_rule_remover3(r0, 0, 0));
	r2 = ft_rule2_maker(str);
	if (!r2)
		return (ft_rule_remover3(r0, r1, 0));
	r3 = ft_rule3_maker(str);
	if (!r3)
		return (ft_rule_remover3(r0, r1, r2));
	return (ft_best_rule(r0, r1, r2, r3));
}
