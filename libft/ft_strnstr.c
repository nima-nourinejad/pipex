/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:20:36 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/08 15:03:21 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *h, char *n)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (n[i] != '\0')
	{
		if (h[i] == n[i])
			counter++;
		i++;
	}
	return (counter);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	if (n != 0 && (h != 0 || len == 0))
	{
		if (ft_strlen(n) == 0)
			return (h);
		if (ft_strlen(n) > len)
			return (0);
	}
	while (*h != '\0')
	{
		if (ft_strlen(n) > ft_strlen(h) || ft_strlen(n) > len)
			return (0);
		if (check(h, n) == (int)ft_strlen(n))
			return (h);
		h++;
		len--;
	}
	return (0);
}
