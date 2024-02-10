/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:51:44 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 16:28:48 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check_sh(char *str, int pos)
{
	int		i;
	char	*temp;

	if (pos == 0)
		temp = ft_pos0_maker(str);
	else
		temp = ft_pos1_maker(str);
	if (!temp)
		exit (-6);
	i = 0;
	while (temp[i])
		i++;
	if ((temp[i - 1] == 'h' && temp[i - 2] == 's' && temp[i - 3] == '.'))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

char	**ft_args0_maker(char *str)
{
	char	**split;
	char	*temp;
	int		i;

	if (ft_check_sh(str, 0))
		return (ft_args2_maker(str));
	split = ft_split_pipex(str, ' ');
	if (!split)
		exit (-6);
	i = 0;
	while (split[i])
	{
		temp = split[i];
		if (i == 0)
			split[i] = ft_pos0_maker(split[i]);
		else
			split[i] = ft_pos1_maker(split[i]);
		if (!split[i])
			exit (-6);
		free (temp);
		i++;
	}
	return (split);
}

char	**ft_args1_maker(char *str)
{
	char	**split;
	char	*temp;
	int		i;

	if (ft_check_sh(str, 1))
		return (ft_args3_maker(str));
	split = ft_split_pipex(str, ' ');
	if (!split)
		exit (-6);
	i = 0;
	while (split[i])
	{
		temp = split[i];
		split[i] = ft_pos1_maker(split[i]);
		if (!split[i])
			exit (-6);
		free (temp);
		i++;
	}
	return (split);
}

char	**ft_args2_maker(char *str)
{
	char	*pos;
	char	**args;

	pos = ft_pos0_maker(str);
	if (!pos)
		exit (-6);
	args = malloc(2 * sizeof(char *));
	if (!args)
		exit (-6);
	args[1] = 0;
	args[0] = pos;
	return (args);
}

char	**ft_args3_maker(char *str)
{
	char	*pos;
	char	**args;

	pos = ft_pos1_maker(str);
	if (!pos)
		exit (-6);
	args = malloc(2 * sizeof(char *));
	if (!args)
		exit (-6);
	args[1] = 0;
	args[0] = pos;
	return (args);
}
