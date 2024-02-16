/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:06:22 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:32 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_rule	*ft_rule0_maker(const char *str, char **envp)
{
	char	**args;
	char	*add;
	t_rule	*n;
	char	*start;

	n = malloc(sizeof(t_rule));
	if (!n)
		return (ft_broken_rule_cleaner(0, 0, 0));
	args = ft_args0_maker((char *)str);
	if (!args)
		return (ft_broken_rule_cleaner(n, 0, 0));
	start = ft_first_part((char *)str);
	if (!start)
		return (ft_broken_rule_cleaner(n, args, 0));
	(*n).first = start;
	(*n).args = args;
	(*n).f = ft_f_path(args[0], envp);
	(*n).x = ft_x_path(args[0], envp);
	add = ft_add_maker(args[0], envp);
	if (!add && (*n).x)
		return (ft_broken_rule_cleaner(n, args, start));
	(*n).add = ft_full_add(add, (*n).x);
	(*n).cmd = ft_full_cmd(start, args, (*n).x);
	return (n);
}

t_rule	*ft_rule1_maker(const char *str, char **envp)
{
	char	**args;
	char	*add;
	t_rule	*n;
	char	*start;

	n = malloc(sizeof(t_rule));
	if (!n)
		return (ft_broken_rule_cleaner(0, 0, 0));
	args = ft_args1_maker((char *)str);
	if (!args)
		return (ft_broken_rule_cleaner(n, 0, 0));
	start = ft_first_part((char *)str);
	if (!start)
		return (ft_broken_rule_cleaner(n, args, 0));
	(*n).first = start;
	(*n).args = args;
	(*n).f = ft_f_path(args[0], envp);
	(*n).x = ft_x_path(args[0], envp);
	add = ft_add_maker(args[0], envp);
	if (!add && (*n).x)
		return (ft_broken_rule_cleaner(n, args, start));
	(*n).add = ft_full_add(add, (*n).x);
	(*n).cmd = ft_full_cmd(start, args, (*n).x);
	return (n);
}

t_rule	*ft_rule2_maker(const char *str)
{
	char	**args;
	char	*add;
	t_rule	*n;
	char	*start;

	n = malloc(sizeof(t_rule));
	if (!n)
		return (ft_broken_rule_cleaner(0, 0, 0));
	args = ft_args0_maker((char *)str);
	if (!args)
		return (ft_broken_rule_cleaner(n, 0, 0));
	start = ft_first_part((char *)str);
	if (!start)
		return (ft_broken_rule_cleaner(n, args, 0));
	(*n).first = start;
	(*n).args = args;
	(*n).f = ft_f_root(args[0]);
	(*n).x = ft_x_root(args[0]);
	add = ft_strdup(args[0]);
	if (!add && (*n).x)
		return (ft_broken_rule_cleaner(n, args, start));
	(*n).add = ft_full_add(add, (*n).x);
	(*n).cmd = ft_full_cmd(start, args, (*n).x);
	return (n);
}

t_rule	*ft_rule3_maker(const char *str)
{
	char	**args;
	char	*add;
	t_rule	*n;
	char	*start;

	n = malloc(sizeof(t_rule));
	if (!n)
		return (0);
	args = ft_args1_maker((char *)str);
	if (!args)
		return (ft_broken_rule_cleaner(n, 0, 0));
	start = ft_first_part((char *)str);
	if (!start)
		return (ft_broken_rule_cleaner(n, args, 0));
	(*n).first = start;
	(*n).args = args;
	(*n).f = ft_f_root(args[0]);
	(*n).x = ft_x_root(args[0]);
	add = ft_strdup(args[0]);
	if (!add && (*n).x)
		return (ft_broken_rule_cleaner(n, args, start));
	(*n).add = ft_full_add(add, (*n).x);
	(*n).cmd = ft_full_cmd(start, args, (*n).x);
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
		if ((*rule).first)
			free((*rule).first);
		free(rule);
	}
}
