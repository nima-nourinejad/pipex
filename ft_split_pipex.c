/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:10:21 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:03 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;
	int	triger1;
	int	triger2;

	count = 0;
	triger1 = 0;
	triger2 = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 0)
			count++;
		else if ((s[i] != c) && (s[i - 1] == c)
			&& triger1 == 0 && triger2 == 0)
			count++;
		triger1 = ft_triger_maker_sp(triger1, s[i], s[i - 1], 34);
		triger2 = ft_triger_maker_sp(triger2, s[i], s[i - 1], 39);
		i++;
	}
	return (count);
}

static int	ft_len(char const *s, char c)
{
	int	j;

	j = 0;
	if (*s == c)
	{
		while (!((s[j] != c)
				&& (s[j + 1] == '\0' || s[j + 1] == c)))
			j++;
	}
	else if ((*s != 34 && *s != 39))
	{
		while (!((s[j] != c && s[j] != '\\')
				&& (s[j + 1] == '\0' || s[j + 1] == c)))
			j++;
	}
	else
		j = ft_len_helper(s);
	return (j + 1);
}

static char	*ft_dup(char const *s, char c)
{
	int		len;
	char	*m;
	int		i;

	len = ft_len(s, c);
	m = malloc ((len + 1) * sizeof(char));
	if (!m)
		return (0);
	m[len] = '\0';
	i = 0;
	while (i < len)
	{
		m[i] = s[i];
		i++;
	}
	return (m);
}

static char	**ft_create(char const *s, char c, int i, int j)
{
	char	**m;
	int		triger1;
	int		triger2;

	m = malloc((ft_count(s, c) + 1) * sizeof (char *));
	if (m == 0)
		return (0);
	m[ft_count(s, c)] = 0;
	triger1 = 0;
	triger2 = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || (i > 0 && s[i - 1] == c && (s[i] != c)))
			&& triger1 == 0 && triger2 == 0)
		{
			m[j] = ft_dup(s + i, c);
			if (m[j] == 0)
				return (ft_free_split(&m, j));
			j++;
		}
		triger1 = ft_triger_maker_sp(triger1, s[i], s[i - 1], 34);
		triger2 = ft_triger_maker_sp(triger2, s[i], s[i - 1], 39);
		i++;
	}
	return (m);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**m;

	if (s == 0)
	{
		m = malloc(1 * sizeof (char *));
		if (m == 0)
			return (0);
		m[0] = 0;
		return (m);
	}
	if (*s == '\0')
		return (ft_split_all_delimiter(s));
	m = ft_create (s, c, 0, 0);
	return (m);
}
