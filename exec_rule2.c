/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rule2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:29:43 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/16 12:24:48 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_rule2(int i, int o, t_ior ior, char **envp)
{
	ft_free_rule_fd(ior.r2, (ior.io).o);
	if ((ior.io).i != -1 && (*(ior.r1)).x == 1)
	{
		dup2(i, 0);
		dup2(o, 1);
		close(i);
		close(o);
		execve((*(ior.r1)).add, (*(ior.r1)).args, envp);
		ft_rule_remover(ior.r1);
	}
	else
	{
		close(o);
		ft_free_rule_fd(ior.r1, (ior.io).i);
	}
}
