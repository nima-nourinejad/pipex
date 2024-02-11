/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rule3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:29:43 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/11 17:27:58 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec_rule3(int i, int o, t_ior ior, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		ft_free_exit_ior (ior, -4);
	if (pid == 0)
	{
		if ((ior.io).i != (ior.io).fd_null)
			close ((ior.io).fd_null);
		ft_free_rule_fd(ior.r1, (ior.io).i);
		dup2(i, 0);
		dup2(o, 1);
		close(i);
		close(o);
		execve((*(ior.r2)).add, (*(ior.r2)).args, envp);
	}
	else
	{
		close(i);
		ft_free_ior_unlink(ior);
		waitpid(pid, &status, 0);
	}
	return ((status >> 8) & 255);
}
