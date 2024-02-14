/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:48:46 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/13 20:15:47 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_number(int argc)
{
	if (argc != 5)
	{
		dup2(2, 1);
		ft_printf("pipex: the wrong number of arguments\n");
		exit (1);
	}
}

static t_ior	*ft_close_free_ior(t_rule *r, int in, int out)
{
	if (in != -1)
		close(in);
	if (out != -1)
		close(out);
	if (r)
		ft_rule_remover(r);
	exit (-1);
}

static t_ior	ft_arg_handling(int argc, char **argv, char **envp)
{
	t_ior	ior;

	ft_number(argc);
	ior.io = ft_io(argv[1], argv[4]);
	ior.r1 = ft_final_rule(argv[2], envp);
	if (ior.r1 == 0)
		ft_close_free_ior(0, (ior.io).i, (ior.io).o);
	ior.r2 = ft_final_rule(argv[3], envp);
	if (ior.r2 == 0)
		ft_close_free_ior(ior.r1, (ior.io).i, (ior.io).o);
	return (ior);
}

int	main(int argc, char **argv, char **envp)
{
	int		p[2];
	pid_t	pid;
	t_ior	ior;
	int		status;
	int		wait;

	status = 0;
	ior = ft_arg_handling(argc, argv, envp);
	if (pipe(p) == -1)
		ft_free_exit_ior(ior, -2);
	pid = fork();
	if (pid == -1)
		ft_free_exit_ior(ior, -3);
	if (pid == 0)
	{
		close(p[0]);
		ft_exec_rule2((ior.io).i, p[1], ior, envp);
	}
	else
	{
		close(p[1]);
		status = ft_exec_rule3(p[0], (ior.io).o, ior, envp);
		waitpid(pid, &wait, 0);
	}
	exit (status);
}
