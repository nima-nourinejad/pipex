/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rule2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:29:43 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 18:20:13 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_rule2(int i, int o, t_ior ior, char **envp)
{
	if ((ior.io).i != (ior.io).fd_null)
		close ((ior.io).fd_null);
	ft_free_rule_fd(ior.r2, (ior.io).o);
	dup2(i, 0);
	dup2(o, 1);
	close(i);
	close(o);
	execve((*(ior.r1)).add, (*(ior.r1)).args, envp);
}
