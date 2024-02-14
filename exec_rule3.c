/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rule3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:29:43 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/14 13:58:11 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_status_handling(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS (status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	else
		return (-8);
}

static int	ft_first_check(t_ior ior)
{
	if ((ior.io).o == -1)
	{
		ft_free_ior(ior);
		return (1);
	}
	if ((*(ior.r2)).f == 1 && (*(ior.r2)).x == 0)
	{
		ft_free_ior(ior);
		return (126);
	}
	else
	{
		ft_free_ior(ior);
		return (127);
	}
}

static void	ft_dup_close(int i, int o)
{
	dup2(i, 0);
	dup2(o, 1);
	close(i);
	close(o);
}

int	ft_exec_rule3(int i, int o, t_ior ior, char **envp)
{
	pid_t	pid;
	int		status;

	status = 0;
	if ((ior.io).o == -1 || (*(ior.r2)).x == 0)
		return (ft_first_check(ior));
	ft_free_rule_fd(ior.r1, (ior.io).i);
	pid = fork();
	if (pid == -1)
		ft_free_exit_ior (ior, -4);
	if (pid == 0)
	{
		ft_dup_close(i, o);
		execve((*(ior.r2)).add, (*(ior.r2)).args, envp);
		ft_free_rule_fd(ior.r2, (ior.io).o);
	}
	else
	{
		close(i);
		ft_free_rule_fd(ior.r2, (ior.io).o);
		waitpid(pid, &status, 0);
	}
	return (ft_status_handling(status));
}
