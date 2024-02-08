/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rule3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:29:43 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/08 17:26:55 by nnourine         ###   ########.fr       */
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
		ft_free_exit_ior (ior, -5);
	if (pid == 0)
	{
		dup2(i, 0);
		dup2(o, 1);
		execve((*(ior.r2)).add, (*(ior.r2)).args, envp);
	}
	else
		waitpid(pid, &status, 0);
	status = (status >> 8) & 255;
	return (status);
}
