/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:44:57 by nima              #+#    #+#             */
/*   Updated: 2024/02/15 10:58:07 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_all_delimiter(char const *s)
{
	char	**m;

	m = malloc(2 * sizeof (char *));
	if (m == 0)
		return (0);
	m[1] = 0;
	m[0] = ft_strdup(s);
	if (!m[0])
	{
		free(m);
		return (0);
	}
	return (m);
}

char	*ft_full_add(char *add, int x)
{
	if (x)
		return (add);
	else
		return (0);
}

char	*ft_full_cmd(char *first, char **args, int x)
{
	if (x)
		return (args[0]);
	else
		return (first);
}

int	ft_len_helper(const char	*s)
{
	int	j;

	j = 0;
	if (*s == 34)
	{
		while ((s[j + 1] != 34 || (s[j] == '\\' || s[j + 1] == 34))
			&& s[j + 1] != '\0')
			j++;
	}
	else
	{
		while ((s[j + 1] != 39 || (s[j] == '\\' || s[j + 1] == 39))
			&& s[j + 1] != '\0')
			j++;
	}
	return (j);
}
