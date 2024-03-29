/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:37:17 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:29 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_rule_check(t_rule *r)
{
	if ((*r).f == 1 && (*r).x == 0)
	{
		dup2(2, 1);
		ft_printf("pipex: %s: permission denied\n", (*r).cmd);
	}
	else if ((*r).f == 0)
	{
		dup2(2, 1);
		ft_printf("pipex: %s: command not found\n", (*r).cmd);
	}
}
