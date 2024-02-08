/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:59:38 by nnourine          #+#    #+#             */
/*   Updated: 2024/01/30 11:10:53 by nnourine         ###   ########.fr       */
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
		return (0);
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
			return (0);
		pos1 = ft_scape(trim);
		free(trim);
		if (!pos1)
			return (0);
	}
	return (pos1);
}

// static char	**ft_free(char **split, int j)
// {
// 	int		i;

// 	i = 0;
// 	while (split[i] && i < j)
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free (split);
// 	return (0);
// }

// char	**ft_full_pos(char *str)
// {
// 	char	**pos;

// 	pos = malloc(3 * sizeof(char *));
// 	if (!pos)
// 		return (ft_free(pos, 0));
// 	pos[2] = 0;
// 	pos[0] = ft_pos0_maker(str);
// 	if (!pos[0])
// 		return (ft_free(pos, 0));
// 	pos[1] = ft_pos1_maker(str);
// 	if (!pos[1])
// 		return (ft_free(pos, 1));
// 	ft_printf("raw cmd:%s\n", str);
// 	ft_printf("pos[0]:%s\n", pos[0]);
// 	ft_printf("pos[1]:%s\n", pos[1]);
// 	return (pos);
// }