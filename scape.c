/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:56:40 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/08 17:57:34 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_scape	ft_remover(t_scape tool)
{
	int		len;
	char	*new;
	int		dif;

	len = (int) ft_strlen(tool.without);
	dif = (tool.index - tool.without);
	new = malloc(len * sizeof(char));
	if (!new)
	{
		tool.without = 0;
		tool.index = 0;
	}
	else
	{
		new[len] = '\0';
		ft_memcpy(new, tool.without, dif);
		ft_memcpy((new + dif),
			(tool.without + dif + 1),
			(len - 1 - dif));
		dif = (tool.index - tool.without);
		tool.without = new;
		tool.index = new + dif + 1;
	}
	return (tool);
}

static int	ft_check_after(char *str)
{
	if (*(str + 1) == '\"' || *(str + 1) == '\'' || *(str + 1) == '\\')
		return (1);
	else
		return (0);
}

t_scape	ft_remover_one(t_scape tool)
{
	int		len;
	char	*temp;

	if (ft_check_after(ft_strchr(tool.index, '\\')))
	{
		temp = tool.without;
		tool.index = ft_strchr(tool.index, '\\');
		tool = ft_remover(tool);
		free(temp);
		if (!tool.without)
		{
			tool.without = 0;
			tool.index = 0;
			return (tool);
		}
	}
	else
	{
		len = (int) ft_strlen(tool.without);
		if ((tool.index + 2) < (tool.without + len))
			tool.index = tool.index + 2;
	}
	return (tool);
}

char	*ft_scape(char *input)
{
	t_scape	tool;
	char	*temp;
	char	*str;

	str = ft_strdup(input);
	if (!str)
		return (0);
	tool.without = str;
	tool.index = tool.without;
	while (ft_strchr(tool.index, '\\'))
	{
		temp = tool.without;
		tool = ft_remover_one(tool);
		if (!tool.without)
			return (0);
	}
	return (tool.without);
}
