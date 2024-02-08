/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rule2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:29:43 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/08 17:56:25 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_rule2(int i, int o, t_ior ior, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		ft_free_exit_ior (ior, -4);
	if (pid == 0)
	{
		dup2(i, 0);
		dup2(o, 1);
		execve((*(ior.r1)).add, (*(ior.r1)).args, envp);
	}
	else
	{
		wait(&status);
		if (status)
			dup2(o, (ior.io).fd_null);
	}
}
