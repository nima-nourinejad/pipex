/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:11:29 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 15:03:58 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_st(char *s, char *set)
{
	int	i;
	int	j;
	int	triger;

	j = 0;
	while (s[j] != '\0')
	{
		i = 0;
		triger = 0;
		while (set[i] != '\0')
		{
			if (s[j] == set[i])
			{
				triger = 1;
			}
			i++;
		}
		if (triger == 0)
			return (j);
		j++;
	}
	return (-1);
}

static int	trim_en(char *s, char *set)
{
	int	i;
	int	l;
	int	triger;

	l = (int) ft_strlen(s);
	while (l > 0)
	{
		i = 0;
		triger = 0;
		while (set[i] != '\0')
		{
			if (s[l - 1] == set[i])
			{
				triger = 1;
			}
			i++;
		}
		if (triger == 0)
			return (l - 1);
		l--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		en;
	char	*d;
	int		l;

	if (s1 == 0 || *s1 == '\0')
		return (ft_strdup(""));
	if (set == 0 || *set == '\0')
		return (ft_strdup(s1));
	st = trim_st((char *)s1, (char *)set);
	en = trim_en((char *)s1, (char *)set);
	if (st == -1 || en == -1)
		return (ft_strdup(""));
	l = en - st + 1;
	if (l < 1)
		return (ft_strdup(""));
	d = malloc((l + 1) * sizeof (char));
	if (d == 0)
		return (0);
	ft_memcpy (d, s1 + st, l);
	d[l] = '\0';
	return (d);
}
