/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:59:38 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/10 16:37:19 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_pos0_maker(char *str)
{
	char	*pos0;

	if (str[0] == '\'')
		pos0 = ft_strtrim(str, "\'");
	else if (str[0] == '\"')
		pos0 = ft_strtrim(str, "\"");
	else
		pos0 = ft_strdup(str);
	if (!pos0)
		exit (-6);
	return (pos0);
}

char	*ft_pos1_maker(char *str)
{
	char	*pos1;
	char	*trim;

	if (*str == '\'')
		pos1 = ft_strtrim(str, "\'");
	else
	{
		if (*str == '\"')
			trim = ft_strtrim(str, "\"");
		else
			trim = ft_strdup(str);
		if (!trim)
			exit (-6);
		pos1 = ft_scape(trim);
		free(trim);
		if (!pos1)
			exit (-6);
	}
	return (pos1);
}
