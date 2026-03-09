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

int		ft_strlen_double(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_double(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_input(void)
{
	char	*path;
	char	**pathreal;
	int		last;

	last = 0;
	pathreal = NULL;
	path = getcwd(NULL, 0);
	if (ft_strcmp(path, "/") == 0)
		ft_printf("%s[ %s ]%s%s[$\xe2\x9e\x9c] %s", GREEN,
			path, RESET, RED, RESET);
	else
	{
		pathreal = ft_strsplit(path, '/');
		last = ft_strlen_double(pathreal);
		ft_printf("%s[ %s ]%s%s[$\xe2\x9e\x9c] %s", GREEN,
			pathreal[last - 1], RESET, RED, RESET);
		ft_free_double(pathreal);
	}
	free(path);
}

char	**ft_strcpy_double(char **arr)
{
	char	**big;
	int		k;
	int		i;

	k = ft_strlen_double(arr);
	i = 0;
	if (!(big = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	big[k] = NULL;
	while (i != k)
	{
		big[i] = ft_strdup(arr[i]);
		i++;
	}
	return (big);
}
