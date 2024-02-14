/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:59:38 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/14 16:54:10 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_not_all_c(char const *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_pos0_maker(char *str)
{
	char	*pos0;

	if (str[0] == '\'' && ft_not_all_c(str, '\''))
		pos0 = ft_strtrim(str, "\'");
	else if (str[0] == '\"' && ft_not_all_c(str, '\"'))
		pos0 = ft_strtrim(str, "\"");
	else
		pos0 = ft_strdup(str);
	if (!pos0)
		return (0);
	return (pos0);
}

char	*ft_pos1_maker(char *str)
{
	char	*pos1;
	char	*trim;

	if (*str == '\'' && ft_not_all_c(str, '\''))
		pos1 = ft_strtrim(str, "\'");
	else
	{
		if (*str == '\"' && ft_not_all_c(str, '\"'))
			trim = ft_strtrim(str, "\"");
		else
			trim = ft_strdup(str);
		if (!trim)
			return (0);
		pos1 = ft_scape(trim);
		free(trim);
		if (!pos1)
			return (0);
	}
	return (pos1);
}
