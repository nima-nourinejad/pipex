/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:01:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 17:55:50 by nnourine         ###   ########.fr       */
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
	if (!add)
		exit (-6);
	if (trim)
		free(trim);
	return (add);
}

int	ft_f_path(char *str, char **envp)
{
	char	**path;
	char	*join;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (1);
	path = ft_all_path(envp);
	join = ft_strjoin("/", str);
	if (!join)
		exit (-6);
	return (ft_check_f(join, path));
}

int	ft_x_path(char *str, char **envp)
{
	char	**path;
	char	*join;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (1);
	path = ft_all_path(envp);
	join = ft_strjoin("/", str);
	if (!join)
		exit (-6);
	return (ft_check_x(join, path));
}

char	*ft_add_maker(char *str, char **envp)
{
	char	**path;
	char	*join;

	if (!str)
		return (0);
	if (str[0] == '\0')
		return (0);
	path = ft_all_path(envp);
	join = ft_strjoin("/", str);
	if (!join)
		exit (-6);
	return (ft_check_add(join, path));
}
