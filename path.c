/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:01:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/08 17:11:06 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_all_path(char **envp)
{
	int		i;
	char	*trim;
	char	**add;

	trim = 0;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			trim = ft_strtrim(envp[i], "PATH=");
			break ;
		}
		i++;
	}
	add = ft_split(trim, ':');
	free(trim);
	return (add);
}

int	ft_f_path(char *str, char **envp, int i)
{
	char	**path;
	char	*join;
	char	*add;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (1);
	path = ft_all_path(envp);
	join = ft_strjoin("/", str);
	while (path[i])
	{
		add = ft_strjoin(path[i], join);
		if (access(add, F_OK) == 0)
		{
			free (add);
			free(join);
			return (1);
		}
		free(add);
		i++;
	}
	free(join);
	return (0);
}

int	ft_x_path(char *str, char **envp, int i)
{
	char	**path;
	char	*join;
	char	*add;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (1);
	path = ft_all_path(envp);
	join = ft_strjoin("/", str);
	while (path[i])
	{
		add = ft_strjoin(path[i], join);
		if (access(add, X_OK) == 0)
		{
			free(join);
			free(add);
			return (1);
		}
		free(add);
		i++;
	}
	free(join);
	return (0);
}

char	*ft_add_maker(char *str, char **envp)
{
	int		i;
	char	**path;
	char	*join;
	char	*add;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (0);
	path = ft_all_path(envp);
	join = ft_strjoin("/", str);
	i = 0;
	while (path[i])
	{
		add = ft_strjoin(path[i], join);
		if (access(add, X_OK) == 0)
		{
			free(join);
			return (add);
		}
		free(add);
		i++;
	}
	free(join);
	return (0);
}
