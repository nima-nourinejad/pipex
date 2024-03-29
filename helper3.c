/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:44:57 by nima              #+#    #+#             */
/*   Updated: 2024/02/16 12:25:11 by nnourine         ###   ########.fr       */
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
	{
		free(add);
		return (0);
	}
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

t_rule	*ft_broken_rule_cleaner(t_rule *n, char **args, char *start)
{
	if (n)
		free (n);
	if (args)
		ft_free_doule_pointer (args);
	if (start)
		free (start);
	return (0);
}
