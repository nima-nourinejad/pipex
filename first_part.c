/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:53:47 by nima              #+#    #+#             */
/*   Updated: 2024/02/14 16:00:47 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_first_part(char const *s)
{
	char	**m;
	char	*first_part;

	m = ft_split_pipex(s, ' ');
	if (!m)
		return (0);
	first_part = ft_strdup(m[0]);
	if (!first_part)
		return (0);
	ft_free_doule_pointer(m);
	return (first_part);
}
