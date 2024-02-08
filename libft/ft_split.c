/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:54:41 by nima              #+#    #+#             */
/*   Updated: 2023/11/08 15:00:08 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	ft_len(char const *s, char c)
{
	int	j;

	j = 0;
	while (!(s[j] != c && (s[j + 1] == '\0' || s[j + 1] == c)))
		j++;
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
	int		k;

	m = malloc((ft_count(s, c) + 1) * sizeof (char *));
	if (m == 0)
		return (0);
	m[ft_count(s, c)] = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (i == 0 || (i > 0 && s[i - 1] == c)))
		{
			m[j] = ft_dup(s + i, c);
			if (m[j] == 0)
			{
				while (k < j)
					free(m[k++]);
				free (m);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (m);
}

char	**ft_split(char const *s, char c)
{
	char	**m;

	if (s == 0 || *s == '\0')
	{
		m = malloc(1 * sizeof (char *));
		if (m == 0)
			return (0);
		m[0] = 0;
		return (m);
	}
	m = ft_create (s, c, 0, 0);
	return (m);
}
