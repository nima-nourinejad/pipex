/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:06:22 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 18:39:13 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_rule	*ft_rule0_maker(char *str, char **envp)
{
	char	**args;
	t_rule	*n;

	n = malloc(sizeof(t_rule));
	if (!n)
		exit (-6);
	args = ft_args0_maker(str);
	if (!args)
		exit (-6);
	(*n).args = args;
	(*n).cmd = args[0];
	(*n).f = ft_f_path(args[0], envp);
	(*n).x = ft_x_path(args[0], envp);
	if ((*n).x)
	{
		(*n).add = ft_add_maker(args[0], envp);
		if (!((*n).add))
			exit (-6);
	}
	else
		(*n).add = 0;
	return (n);
}

t_rule	*ft_rule1_maker(char *str, char **envp)
{
	char	**args;
	t_rule	*n;

	n = malloc(sizeof(t_rule));
	if (!n)
		exit (-6);
	args = ft_args1_maker(str);
	if (!args)
		exit (-6);
	(*n).args = args;
	(*n).cmd = args[0];
	(*n).f = ft_f_path(args[0], envp);
	(*n).x = ft_x_path(args[0], envp);
	if ((*n).x)
	{
		(*n).add = ft_add_maker(args[0], envp);
		if (!((*n).add))
			exit (-6);
	}
	else
		(*n).add = 0;
	return (n);
}

t_rule	*ft_rule2_maker(char *str)
{
	char	**args;
	t_rule	*n;

	n = malloc(sizeof(t_rule));
	if (!n)
		exit (-6);
	args = ft_args2_maker(str);
	if (!args)
		exit (-6);
	(*n).args = args;
	(*n).cmd = args[0];
	(*n).f = ft_f_root(args[0]);
	(*n).x = ft_x_root(args[0]);
	if ((*n).x)
	{
		(*n).add = ft_strdup(args[0]);
		if (!((*n).add))
			exit (-6);
	}
	else
		(*n).add = 0;
	return (n);
}

t_rule	*ft_rule3_maker(char *str)
{
	char	**args;
	t_rule	*n;

	n = malloc(sizeof(t_rule));
	if (!n)
		exit (-6);
	args = ft_args3_maker(str);
	if (!args)
		exit (-6);
	(*n).args = args;
	(*n).cmd = args[0];
	(*n).f = ft_f_root(args[0]);
	(*n).x = ft_x_root(args[0]);
	if ((*n).x)
	{
		(*n).add = ft_strdup(args[0]);
		if (!((*n).add))
			exit (-6);
	}
	else
		(*n).add = 0;
	return (n);
}

void	ft_rule_remover(t_rule *rule)
{
	int		i;
	char	**args;

	if (rule)
	{
		args = (*rule).args;
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
		if ((*rule).add)
			free((*rule).add);
		free(rule);
	}
}
