/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:04:48 by nnourine          #+#    #+#             */
/*   Updated: 2024/01/31 11:52:25 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_f_root(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '\0' || ft_strchr(str, '/') == 0 || ft_strchr(str, ' ') != 0)
		return (0);
	if (access(str, F_OK) == 0)
		return (1);
	return (0);
}

int	ft_x_root(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '\0' || ft_strchr(str, '/') == 0 || ft_strchr(str, ' ') != 0)
		return (0);
	if (access(str, X_OK) == 0)
		return (1);
	return (0);
}
