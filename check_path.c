/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:57:46 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 17:54:00 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_f(char *join, char **path)
{
	int		i;
	char	*add;

	i = 0;
	while (path[i])
	{
		add = ft_strjoin(path[i], join);
		if (!add)
			exit (-6);
		if (access(add, F_OK) == 0)
		{
			ft_free_doule_and_single_pointer(path, add, join);
			return (1);
		}
		free(add);
		i++;
	}
	free(join);
	ft_free_doule_pointer(path);
	return (0);
}

int	ft_check_x(char *join, char **path)
{
	int		i;
	char	*add;

	i = 0;
	while (path[i])
	{
		add = ft_strjoin(path[i], join);
		if (!add)
			exit (-6);
		if (access(add, X_OK) == 0)
		{
			ft_free_doule_and_single_pointer(path, add, join);
			return (1);
		}
		free(add);
		i++;
	}
	free(join);
	ft_free_doule_pointer(path);
	return (0);
}

char	*ft_check_add(char *join, char **path)
{
	int		i;
	char	*add;

	i = 0;
	while (path[i])
	{
		add = ft_strjoin(path[i], join);
		if (!add)
			exit (-6);
		if (access(add, X_OK) == 0)
		{
			ft_free_doule_and_single_pointer(path, 0, join);
			return (add);
		}
		free(add);
		i++;
	}
	ft_free_doule_and_single_pointer(path, 0, join);
	return (0);
}
