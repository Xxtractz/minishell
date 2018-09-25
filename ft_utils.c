/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaloyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:12:18 by mbaloyi           #+#    #+#             */
/*   Updated: 2018/09/13 11:16:29 by mbaloyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_last_path(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return(i);
	free(str);
}

void	ft_input(void)
{
	char	*path;
	char	**pathreal;
	int		last;

	path = NULL;
	path = getcwd(path, sizeof(path));
	pathreal = ft_strsplit(path, '/');
	last = ft_last_path(pathreal);
	ft_printf("%s[ %s ]%s%s[$➜] %s", GREEN, 
		pathreal[last - 1], RESET, RED, RESET);
	free(path);
	free(pathreal);
}